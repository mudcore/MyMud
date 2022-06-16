/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: axe.c
Description: 斧类武器装备标准对象 STD_AXE
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_axe() { return 1; }

void create()
{
    ::create();
    set_name("青铜斧", ({"bronze axe", "axe"}));
    set("long", "用青铜制成的普通斧头。");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "axe", // 武器类型
        "vocation" : ({ "common", "gladiator", "ranger" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 6,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
