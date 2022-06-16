/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: falcon_blade.c
Description: セントシュタイン城下町：14800
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("隼剑", ({"falcon blade", "sword", "blade"}));
    set("long", "寓意拥有像隼一样的速度，使用者出手速度变得极快，必定二连击。");
    add("equip_info", ([
        "lv" : 30, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 12,
        "double" : 1, // 连击
    ]) );
    set("base_value", 2000); // 卖给ＮＰＣ
    set("value", 28000); // 从ＮＰＣ购买
}
