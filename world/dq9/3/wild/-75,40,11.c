/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 1.c
Description: 圣修塔因城地区
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "圣修塔因城西部郊外" NOR);
    set("long", "这里是圣修塔因城西部郊外，向北可以到艾拉菲塔村郊外，向东南再走一段距离就到圣修塔因城了。");
    set("exits", ([
        "northup" : WORLD_9_DIR "4/wild/-75,41,12",
        "east" : __DIR__ "-76,40,11",
        "west" : __DIR__ "-74,40,11",
        "south" : __DIR__ "-75,39,11",
    ]));
    setArea(3, -75, 40, 11);
    setMob(0, 0, 0);
}
