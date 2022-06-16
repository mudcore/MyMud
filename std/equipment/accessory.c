/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: accessory.c
Description: 饰品装备标准继承对象 STD_ACCESSORY
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow/Fist/Shield
*****************************************************************************/
inherit STD_EQUIPMENT;

int is_accessory() { return 1; }

void create()
{
    ::create();
    set_name("兔子尾巴", ({"bunny tail", "tail"}));
    set("long", "软乎乎的很舒服的装饰品。");
    set("unit", "个");
    set("equip_info", ([
        "type" : "accessory", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "luk" : 2,
        "agi" : 2,
    ]) );
}
