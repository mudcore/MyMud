/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: vocation_d.c
Description: 玩家职业系统守护进程 VOCATION_D
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    装备：Sword, Spear, Knife, Wand, Whip, Staff, Claw,
         Fan, Axe, Hammer, Boomerang, Bow, Fist, Shield
    职业："warrior", "priest", "mage", "martial-artist",
         "thief", "minstrel", "gladiator", "paladin",
         "armament-alist", "ranger", "sage", "luminary"
*****************************************************************************/
#include <ansi.h>

nosave string *vocation_list =({
    "warrior", "priest", "mage", "martial-artist",
    "thief", "minstrel", "gladiator", "paladin",
    "armament-alist", "ranger", "sage", "luminary"
});

/**
 * 职业基本信息，equip仅为方便显示用，需和装备属性设置保持一致
 */
nosave mapping vocation_info = ([
    "common" : ([
            "equip"     : ({
                            "sword", "spear", "knife", "whip", "bow",
                            "staff", "claw", "fan", "axe", "hammer",
                            "shield"
                          }),
            "skill"     : ({ "shield" }),
            ]),
    "warrior" : ([
            "equip"     : ({"sword", "spear", "knife", "shield"}),
            "skill"     : ({ "sword", "spear", "knife", "shield", "courage" }),
            ]),

    "priest" : ([
            "equip"     : ({"spear", "wand", "staff", "shield"}),
            "skill"     : ({ "spear", "wand", "staff", "shield", "faith" }),
            ]),

    "mage" : ([
            "equip"     : ({"wand", "knife", "whip", "shield"}),
            "skill"     : ({"wand", "knife", "whip", "shield", "spellcraft"}),
            ]),

    "martial-artist" : ([
            "equip"     : ({"claw", "staff", "fan"}),
            "skill"     : ({"claw", "staff", "fan", "fist", "focus"}),
            ]),

    "thief" : ([
            "equip"     : ({"knife", "sword", "claw"}),
            "skill"     : ({"knife", "sword", "claw", "fist", "treasure"}),
            ]),

    "minstrel" : ([
            "equip"     : ({"sword", "whip", "fan", "shield"}),
            "skill"     : ({"sword", "whip", "fan", "shield", "litheness"}),
            ]),
//以下为上级职业，需要特定条件才可以转职，具体条件由任务ＮＰＣ控制
    "gladiator" : ([
            "equip"     : ({"axe", "hammer", "sword"}),
            "skill"     : ({"axe", "hammer", "sword", "fist", "guts"}),
            ]),

    "paladin" : ([
            "equip"     : ({"hammer", "spear", "wand", "shield"}),
            "skill"     : ({"hammer", "spear", "wand", "shield", "valour"}),
            ]),

    "armament-alist" : ([
            "equip"     : ({"bow", "sword", "wand", "shield"}),
            "skill"     : ({"bow", "sword", "wand", "shield", "fource"}),
            ]),

    "ranger" : ([
            "equip"     : ({"boomerang", "axe", "bow"}),
            "skill"     : ({"boomerang", "axe", "bow", "fist", "ruggedness"}),
            ]),

    "sage" : ([
            "equip"     : ({"wand", "bow", "boomerang", "shield"}),
            "skill"     : ({"wand", "bow", "boomerang", "shield", "enlightenment"}),
            ]),

    "luminary" : ([
            "equip"     : ({"fan", "whip", "boomerang", "shield"}),
            "skill"     : ({"fan", "whip", "boomerang", "shield", "nimbus"}),
            ]),
]);
// 查询职业信息
mapping vocation_info(string vocation)
{
    return vocation_info[vocation];
}

// 转职
int change_vocation(object me, string vocation)
{
    mapping my = me->query_entire_dbase();
    mixed level_info;
    if (member_array(vocation, vocation_list) == -1)
    {
        tell_object(me, HIR "对不起，没有这个职业。\n" NOR);
        return 0;
    }
    if (!stringp(my["vocation"]))
    {
        my["vocation"] = "common";
    }
    /**
     * 转职基础条件检查，更多限制请由相关ＮＰＣ控制
     */
    if (vocation != "minstrel" && my["lv"] < 20)
    {
        tell_object(me, HIR "要转职成其他职业要求当前职业等级至少达到20级。\n" NOR);
        return 0;
    }
    if (my["vocation"] == "common" && vocation != "minstrel")
    {
        tell_object(me, HIR "对不起，平民只能转职为旅艺人(minstrel)职业。\n" NOR);
        return 0;
    }
    if (my["vocation"] == vocation)
    {
        tell_object(me, HIY "你现在就是这个职业呢，如果需要重新开始，请去" HIR "转生" HIY "哦。\n" NOR);
        return 0;
    }
    if (sizeof(me->query_temp("equip")))
    {
        tell_object(me, HIR "请脱掉装备后再来转职吧。\n" NOR);
        return 0;
    }
    /**
     * 转职处理，存取职业数据
     */
    me->set_vocation_info(my["vocation"], "str", my["attr"]["str"]);
    me->set_vocation_info(my["vocation"], "agi", my["attr"]["agi"]);
    me->set_vocation_info(my["vocation"], "vit", my["attr"]["vit"]);
    me->set_vocation_info(my["vocation"], "luk", my["attr"]["luk"]);
    me->set_vocation_info(my["vocation"], "charm", my["attr"]["charm"]);
    me->set_vocation_info(my["vocation"], "mend", my["attr"]["mend"]);
    me->set_vocation_info(my["vocation"], "int", my["attr"]["int"]);
    me->set_vocation_info(my["vocation"], "max_hp", my["attr"]["max_hp"]);
    me->set_vocation_info(my["vocation"], "hp", my["attr"]["hp"]);
    me->set_vocation_info(my["vocation"], "max_mp", my["attr"]["max_mp"]);
    me->set_vocation_info(my["vocation"], "mp", my["attr"]["mp"]);
    me->set_vocation_info(my["vocation"], "sp", my["attr"]["sp"]);
    if (mapp(my["skill"]) && mapp(my["skill"]["sp"]))
    {
        me->set_vocation_info(my["vocation"], "sk1", my["skill"]["sp"]["sk1"]);
        me->set_vocation_info(my["vocation"], "sk2", my["skill"]["sp"]["sk2"]);
        me->set_vocation_info(my["vocation"], "sk3", my["skill"]["sp"]["sk3"]);
        me->set_vocation_info(my["vocation"], "sk4", my["skill"]["sp"]["sk4"]);
        me->set_vocation_info(my["vocation"], "sk5", my["skill"]["sp"]["sk5"]);
    }
    me->set_vocation_info(my["vocation"], "exp", my["exp"]);
    me->set_vocation_info(my["vocation"], "lv", my["lv"]);
    my["vocation"] = vocation;
    if (level_info = me->query_vocation_info(vocation))
    {
        my["exp"] = level_info["exp"];
        my["lv"] = level_info["lv"];
        my["attr"]["str"] = level_info["str"];
        my["attr"]["agi"] = level_info["agi"];
        my["attr"]["vit"] = level_info["vit"];
        my["attr"]["luk"] = level_info["luk"];
        my["attr"]["charm"] = level_info["charm"];
        my["attr"]["mend"] = level_info["mend"];
        my["attr"]["int"] = level_info["int"];
        my["attr"]["max_hp"] = level_info["max_hp"];
        my["attr"]["hp"] = level_info["hp"];
        my["attr"]["max_mp"] = level_info["max_mp"];
        my["attr"]["mp"] = level_info["mp"];
        my["attr"]["sp"] = level_info["sp"];
        if (!mapp(my["skill"])) my["skill"] = ([]);
        if (!mapp(my["skill"]["sp"])) my["skill"]["sp"] = ([]);
        my["skill"]["sp"]["sk1"] = level_info["sk1"];
        my["skill"]["sp"]["sk2"] = level_info["sk2"];
        my["skill"]["sp"]["sk3"] = level_info["sk3"];
        my["skill"]["sp"]["sk4"] = level_info["sk4"];
        my["skill"]["sp"]["sk5"] = level_info["sk5"];
    } else
    {
        level_info = LEVEL_D->level_info(vocation);
        my["exp"] = 0;
        my["lv"] = 1;
        my["attr"]["str"] = level_info[1][0];
        my["attr"]["agi"] = level_info[1][1];
        my["attr"]["vit"] = level_info[1][2];
        my["attr"]["luk"] = level_info[1][3];
        my["attr"]["charm"] = level_info[1][4];
        my["attr"]["mend"] = level_info[1][5];
        my["attr"]["int"] = level_info[1][6];
        my["attr"]["max_hp"] = level_info[1][7];
        my["attr"]["hp"] = level_info[1][7];
        my["attr"]["max_mp"] = level_info[1][8];
        my["attr"]["mp"] = level_info[1][8];
        my["attr"]["sp"] = level_info[1][9];
        // 清除ＳＰ
        if (!mapp(my["skill"])) my["skill"] = ([]);
        my["skill"]["sp"] = ([]);
    }
    // 职业咒文清除
    me->delete_spells();
    me->save();
    return 1;
}
// 转生
void reborn(object me)
{

}
