#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", HIC "街道" NOR);
    set("long", "这里是托拉佩塔城，街上有一个杂货摊。");
    set("dq", 8);
    set("area", 1);
    set("exits", ([
        "west" : __DIR__"city",
        "east" : __DIR__"city4",
    ]));
    set("objects", ([
        __DIR__"npc/dealer2": 1,
    ]) );
    setup();
}
