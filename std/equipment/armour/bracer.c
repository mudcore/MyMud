/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: bracer.c
Description: 护腕装备标准继承对象 STD_BRACER
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("皮护腕", ({"leather gauntlets"}));
    set("long", "由不知道是什么动物的皮革制成的护腕。");
    set("unit", "个");
    set("equip_info", ([
        "type" : "bracer", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
    ]) );
}
