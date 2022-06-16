/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: cotton_trousers.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_TROUSER;

void create()
{
    ::create();
    set_name("布裤子", ({"cotton trousers", "trousers"}));
    set("long", "用布制作的一般裤子。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
