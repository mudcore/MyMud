#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "无尽之海");
    set("long", "这里是等待冒险者征服的无尽之海，海里有数不清的水系魔物偷袭路过的船只。");
    set("exits", ([
        "north" : __DIR__ "sea/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "sea/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "sea/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "sea/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(43, x, y, z);
    setMob(random(3), random(4), random(7));
}
