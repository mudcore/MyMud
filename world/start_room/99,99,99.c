/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: start_room.c
Description: 神灵护佑的地方，新玩家的降生之地
Author: xuefeng
Version: v1.0
*****************************************************************************/

#include <ansi.h>

inherit STD_ROOM;

private void create()
{
    set("short", "天使界");
    set("long", HIW "这里是天使界，据说守护世界的女神就在天使界的某地沉睡，在上空有一片黑暗的区域，透露出扭曲而堕落的力量。" NOR);
    set("no_fight", 1);
    set("exits", ([
        "up" : WORLD_DIR "maze/entry",
        "north" : __DIR__ "99,100,99",
        "south" : __DIR__ "99,98,99",
        "west" : __DIR__ "98,99,99",
        "east" : __DIR__ "100,99,99",
        "down" : __DIR__ "99,99,98",
    ]));

    setArea(0, 99, 99, 99);
    // setup();
    // replace_program(ROOM);
}

void init()
{
    object me = this_player();

    if (!me->in_condition(CD_BLESSING))
    {
        me->start_condition(CD_BLESSING);
    }
    add_action("readme", "screen");
}
