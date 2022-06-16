#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "艾鲁希昂学院地下迷宫");
    set("long", "这里是等待冒险者征服的迷宫，大量的魔物占据了这里。");
    set("exits", ([
        "north" : __DIR__ "dungeon/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "dungeon/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "dungeon/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "dungeon/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(29, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(30))
    {
        set("long", "艾鲁希昂学院地下迷宫，因为魔物的影响，这里变成了一片冒着毒气的沼泽(bog)。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }
    else if (!random(100))
    {
        set("long", "这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", OCEAN);
    }
}
