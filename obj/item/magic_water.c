/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: Magic_water.c
Description: 我方单体MP30多恢复
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIB "魔法圣水" NOR, ({"magic water", "water", "8"}));
    set("long", "我方单体魔力30多恢复。");
    set("base_value", 150);
    set("value", 1500);
    set("unit", "瓶");
    set("effect", ([
        "heal" : ({ "mp", 30, 10}),
    ]) );
}
