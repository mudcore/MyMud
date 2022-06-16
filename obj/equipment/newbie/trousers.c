/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: trousers.c
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
    set_name("初心者布裤", ({"trousers", "trouser"}));
    set("long", "用布制作的普通裤子。");
    set("no_drop", "新手装备不能丢弃，如果不需要了可以卖掉。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 0); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
