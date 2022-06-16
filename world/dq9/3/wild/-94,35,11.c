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
    set("long", "这里是圣修塔因城西部郊外，向西可以到沃尔罗村，向东南再走一段距离就到圣修塔因城了。");
    set("exits", ([
        "westdown" : WORLD_9_DIR "1/wild/-95,35,9",
        "east" : __DIR__ "-93,35,11",
    ]));
    setArea(3, -94, 35, 11);
    setMob(random(3), 2, 0);
}

// 玩家获的世界地图
void init()
{
    object me = this_player();

    if (!arrayp(me->query("worldmap")))
    {
        // 关系后期飞行指令可以飞行的地区
        me->set("worldmap", ({1, 2, 3}));
        tell_object(me, HIR "你获得了世界地图，现在开始可以使用" HIY " map -a " HIR "指令查看世界地图啦。" NOR);
    }

    ::init();
}
