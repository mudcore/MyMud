/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: Bandana.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-19
History:
*****************************************************************************/
inherit STD_HELMET;

void create()
{
    ::create();
    set_name("皮帽", ({"leather hat", "hat"}));
    set("long", "把鞣过的皮缝制在一起的普通帽子。");
    set("equip_effect", ([
        "defense" : 3,
        "mend" : 2,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 180); // 从ＮＰＣ购买
}
