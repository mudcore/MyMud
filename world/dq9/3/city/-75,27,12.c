/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: inn.c
Description: 圣修塔因城的旅馆
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_INN;

private void create()
{
    ::create();
    set("short", HIG "旅店" NOR);
    set("long", "这里是圣修塔因城的旅店，由宿王的女儿莉卡经营，每天都有大量的旅客在这里休息、交流情报或者寻求帮助。");
    setArea(3, -75, 27, 12);
    set("exits", ([
        "south" : __DIR__ "-75,26,12",
        "west" : __DIR__ "-76,27,12",
        "east" : __DIR__ "-74,27,12",
    ]));
    set("objects", ([
        WORLD_9_DIR "1/obj/dqbook" : 1,
        WORLD_9_DIR "3/npc/lika" : 1,
    ]));
    setup();
}
