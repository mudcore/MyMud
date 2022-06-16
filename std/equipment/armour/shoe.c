/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: shoe.c
Description: 脚部装备标准继承对象 STD_SHOE
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("皮靴", ({"wood shield"}));
    set("long", "由动物的毛皮制成的软软的皮靴。");
    set("unit", "双");
    set("equip_info", ([
        "type" : "shoe", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
