/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: armor.c
Description: 护甲装备标准继承对象 STD_ARMOR
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("布衣", ({"cloth"}));
    set("long", "软乎乎的很舒服的布衣。");
    set("equip_info", ([
        "type" : "armor", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
    ]) );
}
