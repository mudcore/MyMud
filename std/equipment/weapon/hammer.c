/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: hammer.c
Description: 锤类武器装备标准对象 STD_HAMMER
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_hammer() { return 1; }

void create()
{
    ::create();
    set_name("棍棒", ({"oaken club", "club"}));
    set("long", "用栎木制作的普通木棒。");
    set("unit", "根");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "hammer", // 武器类型
        "vocation" : ({ "common", "gladiator", "paladin" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 5,
    ]) );
    set("base_value", 10); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
