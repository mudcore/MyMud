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
    set("short", BCYN "艾拉菲塔村郊外" NOR);
    set("long", "这里是艾拉菲塔村郊外，向西北可以到艾拉菲塔村，向南是圣修塔因城地区了。");
    set("exits", ([
        "southdown" : WORLD_9_DIR "3/wild/-75,40,11",
        "east" : __DIR__ "-76,41,12",
        "west" : __DIR__ "-74,41,12",
        "north" : __DIR__ "-75,42,12",
    ]));
    setArea(4, -75, 41, 12);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
