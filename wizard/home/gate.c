#include <ansi.h>

inherit STD_ROOM;

private void create()
{
    ::create();
    set("short", HIG "时空中转站" NOR);
    set("long", "这里是时空中转站，从这里可以到各代DQ的世界。");
    set("exits", ([
        "north" : WORLD_DIR "dq8/1/gate",
        "south" : WORLD_DIR "start_room",
        "void"  : ([ "filename" : "/mudcore/world/area/void.c",
                     "x_axis" : 55,
                     "y_axis" : 5,
                ]),
    ]));
}
