#include <ansi.h>

inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "沃尔罗村郊外山谷" NOR);
    set("long", "这里是沃尔罗村郊外的小山谷，向东北方向可以到圣修塔因城，这里地下一个遗迹。");
    set("exits", ([
        "north" : __DIR__ "-105,16,9",
        "down" : WORLD_9_DIR "2/entrance",
    ]));
    setArea(1, -105, 15, 9);
    setMob(random(2), 2, 0);
}
