/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: combat_d.c
Description: 战斗系统守护进程 COMBAT_D，配合 ATTACK 和 DAMAGE 模块实现战斗相关功能
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
// 常规攻击信息
nosave string *attack_msg = ({
    "$ME无视$YOU的行动，全力发起攻击。",
    "$ME盯著$YOU的一举一动，乘$YOU没有防备突然出招。",
    "$ME慢慢地移动著脚步，然后快速攻击。",
});
// 先制攻击信息
nosave string *pounce_msg = ({
    "$ME乘着$YOU还没准备好，快速发起攻击。",
    "$ME乘$YOU没有防备突然发起攻击。",
});
// 准备攻击信息
nosave string *ready_msg = ({
    "$ME进入了战斗状态。",
    "$ME准备战斗！",
});
// 等待攻击信息
nosave string *wait_msg = ({
    "$ME缓缓地移动脚步，想要找出$YOU的破绽。",
    "$ME目不转睛地盯著$YOU的动作，寻找进攻的最佳时机。",
});
// 防御攻击信息
nosave string *parry_msg = ({
    "但是$ME的攻击被$YOU格挡了。",
    "但是$YOU已有准备，不慌不忙的格挡住$ME的攻击。",
});
// 躲避攻击信息
nosave string *dodge_msg = ({
    "但是$ME的攻击被$YOU机灵地躲开了。",
    "但是$YOU左避右闪，躲过了$ME的攻击。",
    "但是$YOU已有准备，不慌不忙的躲开了$ME的攻击。",
});
// 逃跑信息
nosave string *flee_msg = ({
    "$ME在$YOU没准备好时，抓住机会逃掉了。",
    "$ME目不转睛地盯著$YOU的动作，假装准备攻击，然后突然逃跑了。",
    "$ME慢慢地移动著，然后加快速度转身逃跑了。",
});

// 伤害信息
string damage_msg(int damage, int type)
{
    switch (type)
    {
    case TYPE_C:
        return YEL "$ME发动会心一击，对$YOU造成了 " + damage + " 点爆击伤害。";
    case TYPE_D:
        return element_of(dodge_msg);
    case TYPE_P:
        return element_of(parry_msg);
    default:
        if (damage == 0)
            return "但是$ME的攻击对$YOU没有造成任何伤害。";
        else
            return "$ME对$YOU造成了 " + damage + " 点伤害。";
    }
}

void create()
{
}

// 相克加成
int family_bonus(object me, object victim, int damage)
{
    mapping fm = ([
        "Aquatic": M_AQUATIC,
        "Beast" : M_BEAST,
        "Bird" : M_BIRD,
        "Bug" : M_BUG,
        "Demon" : M_DEMON,
        "Dragon" : M_DRAGON,
        "Elemental" : M_ELEMENTAL,
        "Humanoid" : M_HUMANOID,
        "Machine" : M_MACHINE,
        "Material" : M_MATERIAL,
        "Plant" : M_PLANT,
        "Slime" : M_SLIME,
        "Zombie" : M_ZOMBIE,
        "BOSS" : M_BOSS,
    ]);

    // 如果相克伤害为150%
    if (me->query_fm() & fm[victim->query("family")])
    {
        damage = damage * 150 / 100;
    }
    // 如果是金属史莱姆，最大伤害固定为1
    if (member_array(victim->query("uuid"), ({46, 89, 153, 214, 229})) >= 0)
    {
        // damage = min(({random(5), damage}));
        damage = random(2);
    }

    return damage;
}

// 使用魔法
void do_cast(string spell, object me, mixed who)
{
/**
 * 魔法伤害计算方法
 * [实际伤害值]=[伤害计算值]=(max([初始值],[初始值]+(魔攻-固有魔攻)×增长率)×蓄力倍率)+(等级/10+1)×蓄力次数)×魔防倍率×属性倍率×其他倍率
 *
 * 会心伤害最小值=伤害计算最小值×1.5
 * 会心伤害最大值=伤害计算最大值×2-2
 *
 * 注：魔法攻击由咒文控制
 */
    F_SPELL(spell)->do_effect(me, who);
}

// 使用特技
void do_exert(string skill, object me, mixed who)
{
    F_SKILL(skill)->do_effect(me, who);
}

// 物理攻击
int do_attack(object me, object victim, float ratio)
{
/**
 * 物理伤害计算方法
 * [伤害计算值]=((攻击力×攻击倍率/2-防御力×防御倍率/4)×蓄力倍率)+(等级/10+1)×蓄力次数)×特效倍率×属性倍率×技能倍率×其他倍率
 * [伤害波动]=[伤害计算值]/16+1
 * [实际伤害值]=[伤害计算值]±[伤害波动]
 */
    int attack, damage, defense, random, critical, dodge, parry, regen, attack_type = TYPE_N;
    mapping my, your;
    mapping my_temp, your_temp;
    object weapon;

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();

    if (!(my_temp = me->query_entire_temp_dbase()))
        my_temp = allocate_mapping(9);
    if (!(your_temp = victim->query_entire_temp_dbase()))
        your_temp = allocate_mapping(9);

    attack = me->query_attack();
    defense = victim->query_defense();
    damage = attack / 2 - defense / 4 + my["lv"] / 10 + 1;

    if (userp(me))
    {
        critical = me->query_critical() * 100;
    }
    else
    {
        critical = 1 + my["agi"] / 100;
    }
    if (userp(victim))
    {
        dodge = victim->query_dodge() * 100;
        parry = victim->query_parry() * 100;
    }
    else
    {
        dodge = 1 + your["agi"] / 150;
        parry = 1 + your["vit"] / 250;
    }
/** 会心伤害（暴击）无视防御
 * 会心率=(1+（幸运）器用/100)%
 * [会心伤害基础值]=攻击力×特效倍率
 * [伤害计算值]=[会心伤害基础值]×特效倍率×其他倍率
 * [伤害波动]=[伤害计算值]/16+1
 * [实际伤害值]=[伤害计算值]±[伤害波动]
 */
    if ((random(10000) < critical * 100))
    {
        damage = attack;
        attack_type = TYPE_C;
    }
    else if ((random(10000) < dodge * 100))
    {
        attack_type = TYPE_D;
    }
    else if ((random(10000) < parry * 100))
    {
        attack_type = TYPE_P;
    }

    // 伤害波动
    random = damage / 16 + 1;
    if (random(2))
    {
        damage += random;
    }
    else
        damage -= random;

    if (damage < 0)
        damage = random(3);
    else
        damage *= ratio;

    if (attack_type == TYPE_D || attack_type == TYPE_P)
    {
        damage = 0;
    }

    // 系列相克加成
    damage = family_bonus(me, victim, damage);

    damage = victim->receive_damage("hp", damage, me);
    msg("RED", damage_msg(damage, attack_type), me, victim);

    // 魔杖攻击吸收MP
    if (mapp(me->query_temp("equip")) &&
        (weapon = me->query_temp("equip")["weapon"]) && weapon->is_wand())
    {
        regen = damage * me->query_mp_rate();
        if (regen < 1)
            regen = 1;
        // 增加回魔能力
        regen = to_int(regen + random(me->mp_regen()));
        if (me->query_max_mp() - me->query_mp() > 0)
        {
            me->receive_damage("mp", -regen, victim);
            msg("magic", "$ME吸收了" + regen + "点魔力", me);
        }
    }
    // 武器攻击吸血效果
    if (regen = me->hp_regen())
    {
        if (me->query_max_hp() - me->query_hp() > 0)
        {
            me->receive_damage("hp", -regen, victim);
            msg("success", "$ME吸收了" + regen + "点生命", me);
        }
    }
    // 武器伤害中毒效果
    if (random = me->query_temp("buff/attr/poison"))
    {
        // debug_message("poison attack");
        if (!random(random))
        {
            victim->start_condition(CD_POISON);
        }
    }
    // 魔物攻击中毒效果
    if (me->is_mob())
    {
        mapping action = me->query("action");
        if (mapp(action) && action["poison"] && !random(action["chance"]))
        {
            victim->start_condition(CD_POISON);
        }
    }

    return damage;
}

// 战斗回合处理
void fight(object me, object victim)
{
    int my_score, your_score, round = me->query_temp("combat_round");
    float ratio = 1.0; // 伤害比例：鞭和回旋镖80%递减

    if (!living(me))
        return; // 昏迷等异常状态
    if (environment(me) != environment(victim))
    {
        // me->remove_enemy(victim);
        // victim->remove_enemy(me);
        return;
    }

    if (!victim->is_fighting(me))
        victim->fight_ob(me);

    // 魅力高的玩家魅惑魔物
    if (me->query_charm())
    {
        /* code */
    }
    // 华丽度高度玩家吸引魔物(暂不引入华丽度概念)
    if (me->query_style())
    {
        /* code */
    }
    // 低级怪物有机率逃跑
    if (!userp(me) && !random(3) && my_score * 3 < your_score)
    {
        msg("combat", element_of(flee_msg), me, victim);
        victim->remove_enemy(me);
        destruct(me);
        return;
    }
    me->set_temp("combat_round", ++round);
    if (me->query_temp("combat_status") == ROUND_WAIT)
    {
        // msg("GRN", "-【第 " + (round - 1) + " 回合，$ME等待行动】-", me);
        // debug_message(me->query("id") + " ROUND_WAIT!");
        msg("combat", element_of(wait_msg), me, victim);
        // 准备攻击
        me->set_temp("combat_status", ROUND_ATTACK);
    }
    else if (me->query_temp("combat_status") == ROUND_ATTACK)
    {
        object weapon, *enemies;
        string action = me->query_temp("combat_action");
        // msg("YEL", "-【第 " + (round - 1) + " 回合，$ME开始行动】-", me);
        // debug_message(me->query("id") + " ROUND_ATTACK!");
        // 开始发起攻击
        if (action) // 使用咒文或特技
        {
            mixed who = me->query_temp("action_target");
            if (find_object(F_SPELL(action)))
            {
                if (!who)
                {
                    if (F_SPELL(action)->spell_type() == TYPE_H)
                    {
                        who = me;
                    }
                    else
                    {
                        who = victim;
                    }
                }
                do_cast(action, me, who);
            }
            else if (find_object(F_SKILL(action)))
            {
                if (!who)
                {
                    who = victim;
                }
                do_exert(action, me, who);
            }
            me->delete_temp("combat_action");
            me->delete_temp("action_target");
        }
        else // 发动普通攻击
        {
            msg("combat", element_of(attack_msg), me, victim);
            if (mapp(me->query_temp("equip")) && (weapon = me->query_temp("equip")["weapon"]))
            {
                if (weapon->is_whip())
                {
                    enemies = me->enemy_team();
                    foreach (victim in enemies)
                    {
                        do_attack(me, victim, ratio);
                        ratio *= 0.8;
                    }
                }
                else if (weapon->is_boomerang())
                {
                    enemies = me->query_enemy();
                    foreach (victim in enemies)
                    {
                        do_attack(me, victim, ratio);
                        ratio *= 0.8;
                    }
                }
                else if (me->query_temp("buff/attr/double"))
                {
                    if (!random(me->query_temp("buff/attr/double")))
                    {
                        // debug_message("double attack");
                        do_attack(me, victim, ratio);
                        do_attack(me, victim, ratio);
                    }
                }
                else
                    do_attack(me, victim, ratio);
            }
            else
                do_attack(me, victim, ratio);
        }

        // 下回合等待敌人攻击
        me->set_temp("combat_status", ROUND_WAIT);
    }
    else // 进入战斗状态
    {
        // debug_message(me->query("id") + " ready!");
        msg("default", element_of(ready_msg), me, victim);
        if (me->query_agi() < victim->query_agi()) // 速度慢的先等待１回合后攻击
        {
            // 有一定几率抢先攻击
            if (!random(5))
            {
                // debug_message(me->query("id") + " will pounce!");
                msg("combat", element_of(pounce_msg), me, victim);
                do_attack(me, victim, ratio);
                me->set_temp("combat_status", ROUND_WAIT);
            }
            else
            {
                // debug_message(me->query("id") + " will wait!");
                me->set_temp("combat_status", ROUND_WAIT);
            }
        }
        else
        {
            // debug_message(me->query("id") + " will attack!");
            me->set_temp("combat_status", ROUND_ATTACK); /* code */
        }
    }
}
