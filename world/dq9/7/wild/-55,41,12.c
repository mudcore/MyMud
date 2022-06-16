/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 1.c
Description: 东贝克赛利亚郊外
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "东贝克赛利亚郊外" NOR);
    set("long", "这里是东贝克赛利亚郊外，向北可以到贝克赛利亚镇，向南是圣修塔因城地区。");
    set("exits", ([
        "southdown" : WORLD_9_DIR "3/wild/-55,40,11",
        "east" : __DIR__ "-56,41,12",
        "west" : __DIR__ "-54,41,12",
        "north" : __DIR__ "-55,42,12",
    ]));
    setArea(7, -55, 41, 12);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
