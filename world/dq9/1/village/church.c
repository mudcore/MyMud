/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: church.c
Description: 沃尔罗村的教堂
Author: xuefeng
Version: v1.0
Date: 2019-03-13
*****************************************************************************/
inherit STD_CHURCH;

private void create()
{
    ::create();
    set("long", "这里是沃尔罗村的教堂，旅行者可以在这里祈祷获得神灵的帮助。");
    setArea(1, 0, 0, 10);
    set("exits", ([
        "out" : ([
            "filename" : WORLD_9_DIR "1/village",
            "x_axis" : 25,
            "y_axis" : 9,
        ]),
        "west" : __DIR__"church1",
        "east" : __DIR__"church2",
    ]));
    set("objects", ([
        WORLD_9_DIR "1/npc/minstrel": 1,
    ]) );
    setup();
}
