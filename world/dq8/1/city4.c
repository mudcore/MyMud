#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", HIC "街道" NOR);
    set("long", "这里是托拉佩塔城，北面是城里最热闹的旅馆。");
    set("dq", 8);
    set("area", 1);
    set("exits", ([
        "enter" : __DIR__"inn",
        "west" : __DIR__"city3",
    ]));
    set("objects", ([
    ]) );
    setup();
}
