/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: pot_lid.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-19
History:
*****************************************************************************/
inherit STD_SHIELD;

void create()
{
    ::create();
    set_name("锅盖", ({"pot lid", "lid", "shield"}));
    set("long", "在锅盖上安装上把手的简单的盾。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
