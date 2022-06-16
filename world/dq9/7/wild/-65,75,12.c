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
    set("long", "这里是东贝克赛利亚郊外，向西可以到西贝克赛利亚郊外，东北方向是贝克赛利亚镇，一路向南可以到圣修塔因城地区。");
    set("exits", ([
        "westup" : WORLD_9_DIR "8/wild/-66,75,13",
        "east" : __DIR__ "-64,75,12",
        "south" : __DIR__ "-65,74,12",
        "north" : __DIR__ "-65,76,12",
    ]));
    setArea(7, -65, 75, 12);
    setMob(0, 0, 0);
}
