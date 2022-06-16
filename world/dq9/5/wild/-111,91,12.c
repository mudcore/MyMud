/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 1.c
Description: 艾拉菲塔村郊外
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "鲁迪亚诺城荒野" NOR);
    set("long", "这里是荒野之森，据说这里森林深处隐藏着一座城堡，东南方向可以到艾拉菲塔村郊外。");
    set("exits", ([
        "southeast" : WORLD_9_DIR "4/wild/-110,90,12",
        "east" : __DIR__ "-110,91,12",
        "west" : __DIR__ "-112,91,12",
        "north" : __DIR__ "-111,92,12",
    ]));
    setArea(5, -111, 91, 12);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
