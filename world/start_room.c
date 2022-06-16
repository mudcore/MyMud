// 玩家出生点
#include <ansi.h>

inherit STD_ROOM;

varargs private void create(int x, int y, int z)
{
    set("short", "天使界");
    set("long", HIW "这里是位于星空深处的天使界，是守护世界的天使们居住的地方，据说女神就在天使界的某地沉睡。" NOR);
    set("no_fight", 1);
    set("exits", ([
        "up" : __DIR__ "start_room/" + x + "," + y + "," + (z + 1),
        "north" : __DIR__ "start_room/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "start_room/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "start_room/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "start_room/" + (x + 1) + "," + y + "," + z,
    ]));
    if (z > 0)
    {
        set("exits/down", __DIR__ "start_room/" + x + "," + y + "," + (z - 1));
    }
    if (z == 99)
    {
        removeExit("up");
    }

    setArea(0, x, y, z);
}

void virtual_start()
{
    if (!random(3))
    {
        set("objects", ([
            WORLD_DIR "npc/angel":random(3),
        ]));
    }

    setup();
}
