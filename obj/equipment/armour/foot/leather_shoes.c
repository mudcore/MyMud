/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: leather_shoes.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_SHOE;

void create()
{
    ::create();
    set_name("皮鞋", ({"leather shoes", "shoes", "shoe"}));
    set("long", "常用而由时髦的皮鞋。");
    set("equip_effect", ([
        "agi" : 5,
    ]) );
    set("base_value", 30); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
