/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: scale_shield.c
Description:
Author: xuefeng
Version: v1.0
*****************************************************************************/
inherit STD_SHIELD;

void create()
{
    ::create();
    set_name("鳞盾", ({"scale shield", "shield"}));
    set("long", "在木板上拉上皮制成的朴素的盾。");
    set("equip_effect", ([
        "defense" : 9,
    ]) );
    set("base_value", 30); // 卖给ＮＰＣ
    set("value", 220); // 从ＮＰＣ购买
}
