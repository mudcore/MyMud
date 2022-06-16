/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: wayfarer_clothes.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOR;

void create()
{
    ::create();
    set_name("旅行者之服", ({"wayfarer clothes", "clothes"}));
    set("long", "旅人喜欢穿的结实的麻布衣服。");
    set("equip_effect", ([
        "defense" : 5,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
