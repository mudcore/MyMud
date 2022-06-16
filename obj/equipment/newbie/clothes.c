/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: clothes.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOR;

void create()
{
    ::create();
    set_name("初心者布衣", ({"clothes"}));
    set("long", "用布制作的及其普通的服装。");
    set("no_drop", "新手装备不能丢弃，如果不需要了可以卖掉。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 0); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
