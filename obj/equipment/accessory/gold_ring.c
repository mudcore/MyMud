/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: gold_ring.c
Description: 金戒指 DQ9
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_ACCESSORY;

void create()
{
    ::create();
    set_name("金戒指", ({"gold ring", "ring"}));
    set("long", "一枚制作精良的金戒指。");
    set("unit", "枚");
    set("equip_effect", ([
        "defense" : 2,
    ]) );
}
