/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: iron_sword.c
Description: ベクセリア：1000
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("铁剑", ({"iron sword", "sword"}));
    set("long", "使用百炼精铁打造的长剑，非常耐用。");
    add("equip_info", ([
        "lv" : 15, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 27,
    ]) );
    set("base_value", 150); // 卖给ＮＰＣ
    set("value", 1500); // 从ＮＰＣ购买
}
