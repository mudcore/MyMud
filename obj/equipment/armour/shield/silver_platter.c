/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: silver_platter.c
Description:
Author: xuefeng
Version: v1.0
*****************************************************************************/
inherit STD_SHIELD;

void create()
{
    ::create();
    set_name("银盘", ({"silver platter", "shield"}));
    set("long", "一块镀银的盘片，银光灿灿，可以做盾牌提供一定的防护。");
    set("equip_effect", ([
        "defense" : 11,
        "parry" : 0.01,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 300); // 从ＮＰＣ购买
}
