/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: knife.c
Description: 小刀类武器装备标准对象 STD_KNIFE
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_knife() { return 1; }

void create()
{
    ::create();
    set_name("水果刀", ({"paring knife", "knife"}));
    set("long", "用来削水果的小刀。");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "knife", // 武器类型
        "vocation" : ({ "common", "warrior", "mage", "thief" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
