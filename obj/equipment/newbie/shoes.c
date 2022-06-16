/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: shoes.c
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
    set_name("初心者凉鞋", ({"shoes", "shoe"}));
    set("long", "穿着很凉快的拖鞋。");
    set("no_drop", "新手装备不能丢弃，如果不需要了可以卖掉。");
    set("equip_effect", ([
        "agi" : 3,
    ]) );
    set("base_value", 0); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
