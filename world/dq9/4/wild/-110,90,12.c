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
    set("long", "这里是艾拉菲塔村郊外，向西北可以进入荒野之森，向东南是艾拉菲塔村。");
    set("exits", ([
        "northwest" : WORLD_9_DIR "5/wild/-111,91,12",
        "east" : __DIR__ "-109,90,12",
        "west" : __DIR__ "-111,90,12",
        "south" : __DIR__ "-110,89,12",
    ]));
    setArea(4, -110, 90, 12);
    setMob(0, 0, 0);
}
