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
    set("short", BCYN "鲁迪亚诺城废墟门口" NOR);
    set("long", "这里是鲁迪亚诺城废墟，一座破败的城堡，昏暗的环境中充满了危险，大量的魔物隐藏在这里。");
    set("exits", ([
        "out" : WORLD_9_DIR "5/wild/-125,109,12",
        "east" : __DIR__ "-124,110,13",
        "west" : __DIR__ "-126,110,13",
        "north" : __DIR__ "-125,111,13",
    ]));
    setArea(6, -125, 110, 13);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
