/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: leather_armour.c
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
    set_name("皮甲", ({"leather armour", "armour", "armor"}));
    set("long", "用鞣过的皮制成的简单铠甲。");
    set("equip_effect", ([
        "defense" : 7,
    ]) );
    set("base_value", 60); // 卖给ＮＰＣ
    set("value", 300); // 从ＮＰＣ购买
}
