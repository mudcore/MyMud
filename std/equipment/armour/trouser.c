/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: trouser.c
Description: 腿部装备标准继承对象 STD_TROUSER
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOUR;

void create()
{
    ::create();
    set_name("皮裤", ({"leather trouser"}));
    set("long", "由动物的毛皮制成的皮短裤。");
    set("unit", "条");
    set("equip_info", ([
        "type" : "trouser", // 装备类型
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
