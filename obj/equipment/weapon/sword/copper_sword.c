/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: copper_sword.c
Description: 铜剑，ウォルロ村：150
Author: xuefeng
*****************************************************************************/
inherit STD_SWORD;

void create()
{
    ::create();
    set_name("铜剑", ({"copper sword", "sword"}));
    set("long", "使用铜炼制的极为常见的剑。");
    set("equip_effect", ([
        "damage" : 8,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
