/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: shield.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-19
History:
*****************************************************************************/
inherit STD_SHIELD;

void create()
{
    ::create();
    set_name("初心者盾牌", ({"shield", "pot lid"}));
    set("long", "在锅盖上安装上把手的简单的盾。");
    set("no_drop", "新手装备不能丢弃，如果不需要了可以卖掉。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 0); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
