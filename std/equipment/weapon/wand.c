/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: wand.c
Description: 杖类武器装备标准对象 STD_WAND
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_wand() { return 1; }

void create()
{
    ::create();
    set_name("橡木杖", ({"oak staff", "staff", "wand"}));
    set("long", "用橡木削成的普通魔杖。");
    set("unit", "根");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "wand", // 武器类型
        "vocation" : ({ "priest", "mage", "paladin",
                        "armament-alist", "sage" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 3,
        "mp_rate" : 0.01, // MP吸收率
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 250); // 从ＮＰＣ购买
}
