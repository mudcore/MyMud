/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: warrior_sword.c
Description: 任务奖励
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("战士之剑", ({"warrior sword", "sword"}));
    set("long", "战场上老兵使用的重剑，极具杀伤力。");
    add("equip_info", ([
        "lv" : 30, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 63,
    ]) );
    set("base_value", 1500); // 卖给ＮＰＣ
    set("value", 15000); // 从ＮＰＣ购买
}
