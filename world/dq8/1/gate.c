#include <ansi.h>

inherit STD_OUTDOORS;

private void create()
{
    ::create();
    set("short", BCYN "托拉佩塔城门" NOR);
    set("long", "这里是托拉佩塔城门，城外有魔物，实力不足的不要轻易出城呀。");
    set("dq", 8);
    set("area", 1);
    set("exits", ([
        "north" : __DIR__"city",
        "south" : __DIR__"wild/3,14,9",
    ]));
    set("objects", ([
    ]) );
    setup();
}
