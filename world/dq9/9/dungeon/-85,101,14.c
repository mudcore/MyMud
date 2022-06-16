/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 1.c
Description: 封印之祠
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "封印之祠门口" NOR);
    set("long", "这里是封印之祠门口，在这里封印着瘟疫恶魔，但是因为封印的破损，让这里魔物横行。");
    set("exits", ([
        "out" : WORLD_9_DIR "8/wild/-85,100,13",
        "west" : __DIR__ "-86,101,14",
        "east" : __DIR__ "-84,101,14",
        "north" : __DIR__ "-85,102,14",
    ]));
    setArea(9, -85, 101, 14);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
