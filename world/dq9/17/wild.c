#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "萨玛隆");
    set("long", "这里是等待冒险者征服的地区，无数的魔物等待清理。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(17, x, y, z);
    setMob(random(3), random(4), random(7));
}
