#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "绝望与憎恶魔宫");
    set("long", "这里是绝望与憎恶魔宫，大量强大的魔物占据了这里计划着毁灭整个世界。");
    set("exits", ([
        "north" : __DIR__ "dungeon/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "dungeon/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "dungeon/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "dungeon/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(36, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(20))
    {
        set("long", "绝望与憎恶魔宫，因为魔物的影响，这里变成了一片冒着毒气的沼泽(bog)。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }
    if (!random(100))
    {
        set("long", "这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", OCEAN);
    }
}
