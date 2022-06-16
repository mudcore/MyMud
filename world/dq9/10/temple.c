#include <ansi.h>

inherit STD_ROOM;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "达玛神殿");
    set("long", "这里是位于这个世界中心位置的达玛神殿，这里是被女神祝福的地方，冒险者们可以在这里转职和转生。");
    set("exits", ([
        "north" : __DIR__ "temple/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "temple/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "temple/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "temple/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(10, x, y, z);
    setMob(0, 0, 0);
}
