/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: Holy_water.c
Description: 隐身不遇敌
Author: xuefeng
Version: v1.0
Date: 2019-05-01
History:
*****************************************************************************/
#include <ansi.h>
#include <status.h>

inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIW "圣水" NOR, ({"holy water", "water", "20"}));
    set("long", "10分钟内我方气息隐藏，不会被怪物发现。");
    set("base_value", 100);
    set("value", 1000);
    set("unit", "瓶");
    set("effect", ([
        "status" : ({ STA_INVISIBLE, 600}),
    ]) );
}
