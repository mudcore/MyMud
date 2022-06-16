#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", HIC "街道" NOR);
    set("long", "这里是托拉佩塔城的街道，南面是城里的教堂。");
    set("dq", 8);
    set("area", 1);
    set("exits", ([
        "enter" : __DIR__"church",
        "east" : __DIR__"city1",
    ]));
    set("objects", ([
    ]) );
    setup();
}
