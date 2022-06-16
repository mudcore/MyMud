/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: helmet.c
Description: 头盔装备标准继承对象 STD_HELMET
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("皮帽", ({"leather hat"}));
    set("long", "软乎乎的还防水的皮帽。");
    set("unit", "顶");
    set("equip_info", ([
        "type" : "helmet", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
    ]) );
    set("base_value", 25); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
