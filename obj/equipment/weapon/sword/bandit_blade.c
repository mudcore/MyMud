/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: bandit_blade.c
Description: グビアナ城下町：6300
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("山贼军刀", ({"bandit blade", "sword", "blade"}));
    set("long", "山贼常用的大砍刀，沉重但杀伤力很强。");
    add("equip_info", ([
        "lv" : 30, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 58,
    ]) );
    set("base_value", 800); // 卖给ＮＰＣ
    set("value", 8000); // 从ＮＰＣ购买
}
