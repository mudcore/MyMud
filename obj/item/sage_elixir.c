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
    set_name(HIB "贤者圣水" NOR, ({"sage elixir", "elixir", "9"}));
    set("long", "我方单体魔力90多恢复。");
    set("base_value", 500);
    set("value", 5000);
    set("unit", "瓶");
    set("effect", ([
        "heal" : ({ "mp", 90, 10}),
    ]) );
}
