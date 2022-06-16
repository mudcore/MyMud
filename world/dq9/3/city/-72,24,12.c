#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", HIY "圣修塔因城中心广场" NOR);
    set("long", "这里是圣修塔因城中心，向南可以出城，向北可以到王宫，西北方向是旅店，东北方向是教堂。广场两侧还有杂货铺和装备铺，大量的冒险者来这里买卖物品。");
    setArea(3, -72, 24, 12);

    set("exits", ([
        "north" : __DIR__"-72,22,12",
        "west" : __DIR__"-73,24,12",
        "east" : __DIR__"-71,24,12",
        "south" : __DIR__"-72,23,12",
    ]));
    set("objects", ([
        WORLD_9_DIR "npc/tester": 1,
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
