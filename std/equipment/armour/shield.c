/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: shield.c
Description: 盾牌装备标准继承对象 STD_SHIELD
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow/Shield
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("木盾", ({"wood shield"}));
    set("long", "由一整块木板制成的盾牌。");
    set("unit", "个");
    set("equip_info", ([
        "type" : "shield", // 装备类型
        "vocation" : ({ "common", "warrior", "priest", "mage", "minstrel",
                        "paladin", "armament-alist", "sage", "luminary"}),
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
    ]) );
    set("base_value", 30); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
