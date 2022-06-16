/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: bow.c
Description: 弓类武器装备标准对象 STD_BOW
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_bow() { return 1; }

void create()
{
    ::create();
    set_name("短弓", ({"short bow", "bow"}));
    set("long", "用弹力十足的竹子制作的普通短弓。");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "bow", // 武器类型
        "vocation" : ({ "armament-alist", "ranger", "sage" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 6,
    ]) );
    set("base_value", 15); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购
}
