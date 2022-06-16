/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: Sandals.c
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
    set_name("凉鞋", ({"sandals", "sandal", "shoe"}));
    set("long", "穿着很凉快的拖鞋。");
    set("equip_effect", ([
        "agi" : 3,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
