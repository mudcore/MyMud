#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", HIC "城中心广场" NOR);
    set("long", "这里是托拉佩塔城中心的广场，南面是城门，北面可以到王宫。");
    set("dq", 8);
    set("area", 1);
    set("exits", ([
        "west" : __DIR__"city1",
        "east" : __DIR__"city3",
        "south" : __DIR__"gate",
    ]));
    set("objects", ([
        __DIR__"npc/girl": 1,
    ]) );
    setup();
}
