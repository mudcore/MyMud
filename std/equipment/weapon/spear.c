/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: spear.c
Description: 枪类武器装备标准对象 STD_SPEAR
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_spear() { return 1; }

void create()
{
    ::create();
    set_name("竹枪", ({"bamboo lance", "lance"}));
    set("long", "用竹子削成的长枪。");
    set("unit", "根");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "spear", // 武器类型
        "vocation" : ({ "common", "warrior", "priest", "paladin" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 6,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 200); // 从ＮＰＣ购买
}
