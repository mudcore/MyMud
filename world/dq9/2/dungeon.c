/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: 2.c
Description: 基萨格纳遗迹，新手试炼任务地区
Author: xuefeng
Version: v1.1
Date: 2019-05-02
History:
*****************************************************************************/
#include <ansi.h>

inherit STD_DUNGEON_9;

void setEntry();

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", HIB "基萨格纳遗迹" NOR);
    set("long", "这里是基萨格纳遗迹，到处都是断壁残垣，魔物潜藏在里面等待着猎物。");
    setArea(2, x, y, z);
    setMob(random(3), random(4), random(7));

    set("exits", ([
        "north" : __DIR__ "dungeon/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "dungeon/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "dungeon/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "dungeon/" + (x + 1) + "," + y + "," + z,
    ]));
    // 随机关闭一个出口
    if (random(3))
    {
        removeRandomExit();
        // 随机关闭第二个出口
        if (random(2))
        {
            removeRandomExit();
        }
    }

    if (!random(20))
    {
        set("long", "这里是基萨格纳遗迹，随时有魔物出没，危险重重，在这里的墙上有一个特殊的印记，应该是其他冒险者留的记号("HIC"mark"NOR")。");
        set("item_desc", ([
            "mark" : "转职之间坐标：" HIY "(-55,-5)\n" NOR,
        ]));
    }
    else if (!random(50))
    {
        set("long", "基萨格纳遗迹深处，因为魔物的影响，这里变成了一片冒着毒气的沼泽("MAG"bog"NOR")。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }

    // 遗迹出口
    if (x == -105 && y == 15 && z == 6)
    {
        set("long", "这里是基萨格纳遗迹，到处都是断壁残垣，魔物潜藏在里面等待着猎物，这里有离开遗迹的唯一出口，如果要深入探索千万不要迷路。");
        addExit("out", WORLD_9_DIR "2/entrance");
    }
    // 转职之间：-55,-5,6
    if (y == -5 && z == 6)
    {
        if (x == -54)
        {
            removeExit("west");
        }
        if (x == -56)
        {
            removeExit("east");
        }
    }
    else if (x == -55 && z == 6)
    {
        if (y == -4)
        {
            // 保证到转职之间的入口正常
            set("short", HIC "基萨格纳遗迹" NOR);
            set("long", "这里是基萨格纳遗迹，到处都是断壁残垣，向南方向的建筑风格很特殊，而且灯火通明，好像有谁住在里面。");
            addExit("south", __DIR__ "dungeon/-55,-5,6");
        }
        if (y == -6)
        {
            removeExit("north");
        }
    }
}

void init()
{
    object me = this_player();
    // 勇气试炼任务
    if (!me->query_temp("BOSS1") && !me->query_quest_finish("BOSS01") && !random(5))
    {
        object room = new(__DIR__ "dungeon/99,99,5");
        msg("warning", "$ME不下心踩到陷阱，直接掉了进去。", me);
        me->move(room);
    }

    ::init();
}
