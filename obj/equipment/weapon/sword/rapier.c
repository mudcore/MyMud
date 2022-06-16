/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: rapier.c
Description: セントシュタイン城下町：480
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("西洋剑", ({"rapier", "sword"}));
    set("long", "源自西洋的长剑，剑身细长，灵活轻巧。");
    set("equip_effect", ([
        "damage" : 19,
        "critical" : 0.01,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 550); // 从ＮＰＣ购买
}
