#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", BCYN "圣修塔因城门" NOR);
    set("long", "这里是圣修塔因城门口，城外有魔物，实力不足的不要轻易出去呀。");
    setArea(3, -72, 21, 12);

    set("exits", ([
        "out" : WORLD_9_DIR "3/wild/-72,20,11",
        "north" : __DIR__"-72,22,12",
    ]));
    set("objects", ([
        WORLD_9_DIR "3/npc/guard": 2,
    ]) );
    setup();
}
