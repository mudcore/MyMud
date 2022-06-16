/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: sword.c
Description: 剑类武器装备标准对象 STD_SWORD
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_sword() { return 1; }

void create()
{
    ::create();
    set_name("柏木剑", ({"rod"}));
    set("long", "用柏木削成的普通木剑");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "sword", // 武器类型
        "vocation" : ({ "common", "warrior", "minstrel", // 职业限制
                        "thief", "gladiator" , "armament-alist" }),
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
    ]) );
    set("base_value", 10); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
