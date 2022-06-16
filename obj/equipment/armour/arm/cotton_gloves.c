/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: cotton_gloves.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_BRACER;

void create()
{
    ::create();
    set_name("布手套", ({"cotton gloves", "gloves"}));
    set("long", "用布做成的普通手套。");
    set("equip_effect", ([
        "luk" : 5,
    ]) );
    set("base_value", 60); // 卖给ＮＰＣ
    set("value", 250); // 从ＮＰＣ购买
}
