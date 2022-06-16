/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: claw.c
Description: 爪类武器装备标准对象 STD_CLAW
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_claw() { return 1; }

void create()
{
    ::create();
    set_name("石爪", ({"stone claws", "claw", "claws"}));
    set("long", "用石头磨制成的爪套。");
    set("unit", "双");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "claw", // 武器类型
        "vocation" : ({ "common", "martial-artist", "thief" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 7,
    ]) );
    set("base_value", 15); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
