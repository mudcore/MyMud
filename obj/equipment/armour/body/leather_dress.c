/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: leather_dress.c
Description: 女生喜欢穿的裙子
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOR;

void create()
{
    ::create();
    set_name("皮裙", ({"leather dress", "dress"}));
    set("long", "用兽皮制成的轻便漂亮的裙子。");
    set("equip_info", ([
        "type" : "armor", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 2, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 6,
        "mend" : 3,
    ]) );
    set("base_value", 70); // 卖给ＮＰＣ
    set("value", 350); // 从ＮＰＣ购买
}
