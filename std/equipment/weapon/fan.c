/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: fan.c
Description: 扇类武器装备标准对象 STD_FAN
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow
*****************************************************************************/
inherit STD_WEAPON;

int is_fan() { return 1; }

void create()
{
    ::create();
    set_name("羽扇", ({"feather fan", "fan"}));
    set("long", "用羽毛和木头制成的普通扇子。");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "fan", // 武器类型
        "vocation" : ({ "common", "martial-artist", "minstrel", "luminary" }), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
    ]) );
    set("base_value", 10); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
