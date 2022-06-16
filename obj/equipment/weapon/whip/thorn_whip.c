/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: thorn_whip.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
*****************************************************************************/
inherit STD_WHIP;

void create()
{
    ::create();
    set_name("荆棘鞭", ({"thorn whip", "whip"}));
    set("long", "用荆棘制成的长鞭，上面布满倒刺。");
    set("equip_effect", ([
        "damage" : 11,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 500); // 从ＮＰＣ购买
}
