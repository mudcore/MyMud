/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: leather_whip.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_WHIP;

void create()
{
    ::create();
    set_name("皮鞭", ({"leather whip", "whip"}));
    set("long", "可攻击一组敌人的皮质鞭子。");
    set("equip_effect", ([
        "damage" : 5,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
