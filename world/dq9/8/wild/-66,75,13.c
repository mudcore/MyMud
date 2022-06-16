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
    set("short", BCYN "西贝克赛利亚郊外" NOR);
    set("long", "这里是西贝克赛利亚郊外，向东可以到贝克赛利亚镇。在这个地区的西北角有一个封印之祠，封印着瘟疫恶魔。");
    set("exits", ([
        "eastdown" : WORLD_9_DIR "7/wild/-65,75,12",
        "west" : __DIR__ "-67,75,13",
        "south" : __DIR__ "-66,74,13",
        "north" : __DIR__ "-66,76,13",
    ]));
    setArea(8, -66, 75, 13);
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
