/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: church.c
Description: 圣修塔因城的教堂
Author: xuefeng
Version: v1.0
Date: 2020-02-18
*****************************************************************************/
inherit STD_CHURCH;

private void create()
{
    ::create();
    set("long", "这里是圣修塔因城的教堂，旅行者可以在这里祈祷获得神灵的帮助。");
    setArea(3, -69, 27, 12);
    set("exits", ([
        "south" : __DIR__"-69,26,12",
        "west" : __DIR__"-70,27,12",
        "east" : __DIR__"-68,27,12",
    ]));
    set("objects", ([
        WORLD_9_DIR "npc/nun": 2,
    ]) );
    setup();
}
