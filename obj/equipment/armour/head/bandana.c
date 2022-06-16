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
    set_name("头巾", ({"bandana", "hat"}));
    set("long", "非常普通的头巾。");
    set("equip_effect", ([
        "defense" : 1,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 90); // 从ＮＰＣ购买
}
