/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: type_m_s.h
Description:单体攻击魔法公共方法
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
/**
 * 小于咒语固有魔攻时伤害直接是[初始值]
 * 大于固有魔攻时伤害是[初始值]+(魔攻-固有魔攻)×增长率
 * [实际伤害值]=[伤害计算值]=(max([初始值],[初始值]+(魔攻-固有魔攻)×增长率)×蓄力倍率)+(等级/10+1)×蓄力次数)×魔防倍率×属性倍率×其他倍率
 */
// nosave mapping spell_info = ([
//     "name" : "ice", // 咒文名称
//     "type" : TYPE_M, // 伤害类型
//     "range" : RANGE_S, // 作用范围
//     "base" : 50, // 基础值(固有魔攻)
//     "min"  : 25, // 最小伤害
//     "rand" : 10, // 最大波动值 25 + random(10) = 34
//     "rate" : 0.094, // 增长率
//     "max"  : 999, // 伤害上限
//     "mp"   : 3, // 魔力消耗
// ]);

int do_effect(object me, object ob)
{
    int magic, damage, rand, extra, critical, attack_type;
    string msg;

    if (!objectp(ob) || !me->is_fighting(ob)) {
        return notify_fail("你只能对战斗中的对手使用这个魔法。\n");
    }

    if (me->query_mp() < spell_info["mp"]) {
        me->start_busy(1);
        // return notify_fail("你的魔力不够了。\n");
        msg = "$ME吟唱了" + chinese(spell_info["name"]) + "!但是魔力不够了。";
        msg("info", msg, me);
        return 1;
    }

    magic = me->query_magic();
    rand = random(spell_info["rand"]);
    damage = spell_info["min"] + rand;

    if (userp(me))
        critical = 1 + me->query_luk() / 100;
    else
        critical = 1 + me->query_agi() / 100;

    if((random(100) < critical))
    {
        if(!rand)
            damage = damage * 1.5;
        else
            damage = damage * 2 - 2;

        attack_type = TYPE_C;
    }

    extra = (magic - spell_info["base"]) * spell_info["rate"];
    damage = max( ({damage, damage + extra}) );
    damage += me->query("lv") / 10 + 1;
    damage = min( ({damage, spell_info["max"]}) );
    damage = to_int(damage);

    me->start_busy(1);
    me->add_attr("mp", -spell_info["mp"]);

    if (member_array(ob->query("uuid"), ({46, 89, 153, 214, 229})) < 0)
    {
        if(attack_type == TYPE_C)
        {
            msg = "$ME吟唱了" + chinese(spell_info["name"]) + "，会心一击！对$YOU造成 " + damage + " 点爆击伤害。";
            msg("warning", msg, me, ob);
        } else {
            msg = "$ME吟唱了" + chinese(spell_info["name"]) + "，对$YOU造成 " + damage + " 点伤害。";
            msg("danger", msg, me, ob);
        }
        ob->receive_damage("hp", damage, me);
    }
    else
    {
        msg("info", "但是$ME的魔法好像没有效果，$YOU看起来完好无损。", me, ob);
    }

    return 1;
}

string spell_name(){
    return spell_info["name"];
}

int spell_type(){
    return spell_info["type"];
}

int spell_range(){
    return spell_info["range"];
}
