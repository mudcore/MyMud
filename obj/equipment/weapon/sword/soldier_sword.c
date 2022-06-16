/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: soldier_sword.c
Description: ウォルロ村：240
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("士兵长剑", ({"soldier sword", "sword"}));
    set("long", "给城堡的士兵派发的普通长剑。");
    set("equip_effect", ([
        "damage" : 13,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 250); // 从ＮＰＣ购买
}
