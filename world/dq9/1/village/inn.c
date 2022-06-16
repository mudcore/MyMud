/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: inn.c
Description: 托拉佩塔城的旅馆
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
    set("long", "这里是沃尔罗村的旅店，本来是莉卡经营的，现在由村民打理，过往的旅客都在这里休息回复疲惫的身体。");
    setArea(1, 0, 0, 10);
    set("exits", ([
        "out" : ([
            "filename" : WORLD_9_DIR "1/village",
            "x_axis" : 30,
            "y_axis" : 9,
        ]),
        "west" : __DIR__ "inn1",
        "east" : __DIR__ "inn2",
    ]));
    set("objects", ([
        WORLD_9_DIR "1/obj/dqbook" : 1,
    ]));
    setup();
}
