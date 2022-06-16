/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: leather_shield.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-19
History:
*****************************************************************************/
inherit STD_SHIELD;

void create()
{
    ::create();
    set_name("皮盾", ({"leather shield", "shield"}));
    set("long", "在木板上拉上皮制成的朴素的盾。");
    set("equip_effect", ([
        "defense" : 5,
    ]) );
    set("base_value", 30); // 卖给ＮＰＣ
    set("value", 120); // 从ＮＰＣ购买
}
