#include <ansi.h>

inherit STD_ROOM;

private void create()
{
    ::create();
    set("short", HIY "教堂" NOR);
    set("long", "这里是沃尔罗村的教堂，旅行者可以在这里祈祷获得神灵的帮助。");
    setArea(1, 1, 0, 10);
    set("exits", ([
        "west" : __DIR__"church",
    ]));
    set("objects", ([
        WORLD_9_DIR "1/npc/villager": 2,
    ]) );
    setup();
}
