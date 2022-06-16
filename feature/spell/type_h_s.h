/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: type_h_s.h
Description:单体治疗魔法公共方法
Author: xuefeng
Version: v1.0
Date: 2019-03-23
History:
*****************************************************************************/
/**
 * 小于咒语固有魔回时恢复直接是[初始值]
 * 大于固有魔回时恢复是[初始值]+(魔回-固有魔回)×增长率
 * [实际恢复值]=[恢复计算值]=(max([初始值],[初始值]+(魔回-固有魔回)×增长率)×蓄力倍率)+(等级/10+1)×蓄力次数)×魔防倍率×属性倍率×其他倍率
 */
// nosave mapping spell_info = ([
//     "name" : "heal", // 咒文名称
//     "type" : TYPE_H, // 伤害类型
//     "range" : RANGE_S, // 作用范围
//     "base" : 50, // 基础值(固有魔回)
//     "min"  : 30, // 最小伤害
//     "rand" : 10, // 最大波动值 30 + random(10) = 39
//     "rate" : 0.13172, // 增长率
//     "max"  : 999, // 伤害上限
//     "mp"   : 2, // 魔力消耗
// ]);

int do_effect(object me, object ob)
{
    int magic, damage, rand, extra, critical, attack_type;
    string msg, who;

    if (!objectp(ob)) {
        ob = me;
    }

    if (ob->is_hp_full()) {
        who = (ob == me) ? "你" : ob->name();
        write(who + "现在的状态无需使用治疗魔法。\n");
        return 1;
    }

    if (me->query_mp() < spell_info["mp"]) {
        me->start_busy(1);
        // return notify_fail("你的魔力不够了。\n");
        msg = "$ME吟唱了" + chinese(spell_info["name"]) + "!但是魔力不够了。";
        msg("info", msg, me);
        return 1;
    }

    magic = me->query_mend();
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
    damage = -to_int(damage); // 回复魔法伤害为负

    me->start_busy(1);
    me->add_attr("mp", -spell_info["mp"]);
    if (me == ob) {
        msg = "$ME吟唱了" + chinese(spell_info["name"]) + "!$ME的伤势恢复了。";
        msg("success", msg, me);
    } else {
        msg = "$ME吟唱了" + chinese(spell_info["name"]) + "!$YOU的伤势恢复了。";
        msg("success", msg, me, ob);
    }
    ob->receive_damage("hp", damage, me);

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
