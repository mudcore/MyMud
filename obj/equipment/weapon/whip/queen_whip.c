/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: queen_whip.c
Description:
Author: xuefeng
Version: v1.0
*****************************************************************************/
inherit STD_WHIP;

void create()
{
    ::create();
    set_name("女王之鞭", ({"queen whip", "whip"}));
    set("long", "用荆棘制成的长鞭，上面布满倒刺。");
    add("equip_info", ([
        "lv" : 50, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 80,
    ]) );
    set("base_value", 500); // 卖给ＮＰＣ
    set("value", 50000); // 从ＮＰＣ购买
}
