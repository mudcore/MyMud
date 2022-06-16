/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: staff.c
Description: 棍类武器装备标准对象 STD_STAFF
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_staff() { return 1; }

void create()
{
    ::create();
    set_name("撑衣竿", ({"laundry pole", "pole", "staff"}));
    set("long", "从晒衣服的地方偷来的撑衣竿。");
    set("unit", "根");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "staff", // 武器类型
        "vocation" : ({ "common", "priest", "martial-artist" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
    ]) );
    set("base_value", 10); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
