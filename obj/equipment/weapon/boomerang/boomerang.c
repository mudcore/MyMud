/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: boomerang.c
Description: 回旋镖
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_BOOMERANG;

void create()
{
    ::create();
    set_name("回旋镖", ({"boomerang"}));
    set("long", "普通的回旋镖，可攻击全体敌人，但是伤害会递减。");
    add("equip_info", ([
        "lv" : 10, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 13,
    ]) );
    set("base_value", 100); // 卖给ＮＰＣ
    set("value", 1500); // 从ＮＰＣ购买
}
