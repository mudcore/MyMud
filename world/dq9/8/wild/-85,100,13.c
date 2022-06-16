/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 1.c
Description: 西贝克赛利亚郊外
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "封印之祠外" NOR);
    set("long", "这里是西贝克赛利亚郊外，在这里有一个封印之祠，封印着瘟疫恶魔。");
    set("exits", ([
        "enter" : WORLD_9_DIR "9/dungeon/-85,101,14",
        "west" : __DIR__ "-86,100,13",
        "east" : __DIR__ "-84,100,13",
        "south" : __DIR__ "-85,99,13",
    ]));
    setArea(8, -85, 100, 13);
    setMob(0, 0, 0);
}
