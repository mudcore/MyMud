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
    set("long", "这里是荒野之森，一座巨大而破败的城堡耸立在这里，据说当年这个城堡是繁华的城市。");
    set("exits", ([
        "enter" : WORLD_9_DIR "6/dungeon/-125,110,13",
        "east" : __DIR__ "-124,109,12",
        "west" : __DIR__ "-126,109,12",
        "south" : __DIR__ "-125,108,12",
    ]));
    setArea(5, -125, 109, 12);
    setMob(0, 0, 0);
}
