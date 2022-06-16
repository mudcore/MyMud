/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: skill.h 1 1
Description: 群体攻击特技公共方法
Author: xuefeng
Version: v1.0
*****************************************************************************/
/* 技能设定
nosave mapping skill_info = ([
    "name" : "x-sword", // 技能名称
    "type" : TYPE_S, // 伤害类型
    "range" : RANGE_G, // 作用范围
    "base_rate" : 1.0, // 伤害基准倍率
    "rand" : 0.26, // 伤害倍率波动范围 1.0 ± random(0.6*10) / 10.0
    "times" : 1, // 攻击次数应该固定为1
    "hp_regen" : 0.0, // 吸血比例
    "mp_regen" : 0, // 吸魔比例(非魔杖物理攻击)
    "mp"   : 3, // 魔力消耗
]);
*/
int do_effect(object me, object who)
{
    float ratio;
    int damage;
    string msg;
    object *obs = me->enemy_team();

    if (!me->is_fighting()) {
        return notify_fail("你只能对战斗中的对手使用这个技能。\n");
    }
    if (skill_info["range"] == RANGE_A)
    {
        obs = me->query_enemy();
    }

    if (me->query_mp() < skill_info["mp"]) {
        me->start_busy(1);
        // return notify_fail("你的魔力不够了。\n");
        msg = "$ME发动技能" + chinese(skill_info["name"]) + "!但是魔力不够了。";
        msg("info", msg, me);
        return 1;
    }

    ratio = skill_info["base_rate"];
    foreach(object ob in obs)
    {
        if (skill_info["rand"] > 0)
        {
            if (random(2))
                ratio = skill_info["base_rate"] + random(to_int(skill_info["rand"] * 100)) / 100.0;
            else
                ratio = skill_info["base_rate"] - random(to_int(skill_info["rand"] * 100)) / 100.0;
        }

        damage = COMBAT_D->do_attack(me, ob, ratio);
    }

    me->start_busy(1);
    me->add_attr("mp", -skill_info["mp"]);

    if (damage && skill_info["hp_regen"] > 0)
    {
        damage = to_int(damage * skill_info["hp_regen"]);
        msg = "$ME的 HP 回复了 " + damage + " 点。";
        msg("success", msg, me);
        me->receive_damage("hp", -damage, me);
    }
    if (damage && skill_info["mp_regen"] > 0)
    {
        damage = to_int(damage * skill_info["mp_regen"]);
        msg = "$ME的 MP 回复了 " + damage + " 点。";
        msg("magic", msg, me);
        me->receive_damage("mp", -damage, me);
    }
    return 1;
}

string skill_name(){
    return skill_info["name"];
}

int skill_type(){
    return skill_info["type"];
}

int skill_range(){
    return skill_info["range"];
}
