/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: boomerang.c
Description: 回旋镖类武器装备标准对象 STD_BOOMERANG
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_boomerang() { return 1; }

void create()
{
    ::create();
    set_name("回旋镖", ({"boomerang"}));
    set("long", "一只月芽型的回旋镖。");
    set("unit", "只");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "boomerang", // 武器类型
        "vocation" : ({ "ranger", "sage", "luminary" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 10,
    ]) );
    set("base_value", 100); // 卖给ＮＰＣ
    set("value", 500); // 从ＮＰＣ购买
}
