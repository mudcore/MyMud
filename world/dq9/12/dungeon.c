#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "海滨洞窟");
    set("long", "这里是海滨洞窟的内部，大量的水系魔物占据了这里。");
    set("exits", ([
        "north" : __DIR__ "dungeon/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "dungeon/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "dungeon/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "dungeon/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(12, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(100))
    {
        set("long", "这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", OCEAN);
    }
}
