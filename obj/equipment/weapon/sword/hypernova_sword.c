/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: hypernova_sword.c
Description: 银河之剑 DQ9
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("超级新星之剑", ({"hypernova sword", "sword"}));
    set("long", "使用银河的力量打造的神器。");
    set("unit", "柄");
    add("equip_info", ([
        "lv" : 60, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 180,
    ]) );
    set("base_value", 5000); // 卖给ＮＰＣ
    set("value", 150000); // 从ＮＰＣ购买
}
