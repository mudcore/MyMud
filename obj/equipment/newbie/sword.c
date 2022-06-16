/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: sword.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("初心者木剑", ({"sword", "wood sword"}));
    set("long", "使用乌木制做的普通长剑。");
    set("no_drop", "新手装备不能丢弃，如果不需要了可以卖掉。");
    set("equip_effect", ([
        "damage" : 6,
    ]) );
    set("base_value", 0); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
