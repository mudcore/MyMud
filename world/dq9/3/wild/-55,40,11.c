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
    set("long", "这里是圣修塔因城西部郊外，向北可以到贝克赛利亚镇，向西南再走一段距离就到圣修塔因城了。");
    set("exits", ([
        "northup" : WORLD_9_DIR "7/wild/-55,41,12",
        "east" : __DIR__ "-56,40,11",
        "west" : __DIR__ "-54,40,11",
        "south" : __DIR__ "-55,39,11",
    ]));
    setArea(3, -55, 40, 11);
    setMob(0, 0, 0);
}
