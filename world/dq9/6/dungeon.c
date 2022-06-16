#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "鲁迪亚诺城");
    set("long", "这里是荒野中的一座破败的城堡，昏暗的环境中充满了危险，大量的魔物隐藏在这里。");
    set("exits", ([
        "north" : __DIR__ "dungeon/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "dungeon/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "dungeon/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "dungeon/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(6, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(30))
    {
        set("long", "鲁迪亚诺城深处，因为魔物的影响，这里变成了一片冒着毒气的沼泽("MAG"bog"NOR")。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }
    if (!random(100))
    {
        set("long", "这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", WORLD_9_DIR "5/wild/-125,109,12");
    }
}
