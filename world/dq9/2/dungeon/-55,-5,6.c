#include <ansi.h>

inherit STD_DUNGEON_9;

private void create()
{
    ::create();
    set("short", HIY "转职之间" NOR);
    set("long", "这里是基萨格纳遗迹深处，到达这里的勇者可以转职("HIY"vocation"NOR")，这里还有一个闪闪发光的传送门("HIC"door"NOR")。");
    set("exits", ([
        "out" : WORLD_9_DIR "2/maze1/exit",
        "down" : WORLD_9_DIR "2/maze2/entry",
        "enter" : START_ROOM,
    ]));
    set("objects", ([
       WORLD_9_DIR "2/npc/priest" : 1,
    ]) );
    set("item_desc", ([
        "door": HIW "一座闪耀着白光的传送门，可以通过(enter)这里传送到月神时空。\n" NOR,
    ]));
    set("no_fight", 1);
    setArea(2, -55, -5, 6);
    setMob(0, 0, 0);
    setup();
}
