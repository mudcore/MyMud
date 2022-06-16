/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: whip.c
Description: 鞭类武器装备标准对象 STD_WHIP
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_whip() { return 1; }

void create()
{
    ::create();
    set_name("皮鞭", ({"leather whip", "whip"}));
    set("long", "一根柔韧又结实的皮鞭。");
    set("unit", "根");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "whip", // 武器类型
        "vocation" : ({ "common", "mage", "minstrel", "luminary" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
