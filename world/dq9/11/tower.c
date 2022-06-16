#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "达玛之塔");
    set("long", "这里是达玛之塔的内部。");
    set("exits", ([
        "north" : __DIR__ "tower/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "tower/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "tower/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "tower/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(11, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(100))
    {
        set("long", "这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", OCEAN);
    }
}
