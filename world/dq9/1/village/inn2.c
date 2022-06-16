#include <ansi.h>

inherit STD_ROOM;

int is_inn() { return 1; }

private void create()
{
    ::create();
    set("short", HIG "旅店" NOR);
    set("long", "这里是沃尔罗村的旅店，本来是莉卡经营的，现在由村民打理，过往的旅客都在这里休息回复疲惫的身体。");
    setArea(1, 1, 0, 10);
    set("objects", ([
        WORLD_9_DIR "1/npc/adventurer": 1,
        WORLD_9_DIR "1/obj/dqbook" : 1,
    ]) );
    set("exits", ([
        "west" : __DIR__"inn",
    ]));
    setup();
}
