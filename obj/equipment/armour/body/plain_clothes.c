/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: plain_clothes.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ARMOR;

void create()
{
    ::create();
    set_name("布衣", ({"plain clothes", "clothes"}));
    set("long", "用布制作的及其普通的服装。");
    set("equip_effect", ([
        "defense" : 3,
    ]) );
    set("base_value", 40); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
