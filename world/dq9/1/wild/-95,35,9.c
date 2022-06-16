#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", BCYN "沃尔罗村郊外山路" NOR);
    set("long", "这里是沃尔罗村郊外，向东继续前行就到圣修塔因城了。");
    set("exits", ([
        "west" : __DIR__"-96,35,9",
        "south" : __DIR__"-95,34,9",
        "eastup" : WORLD_9_DIR "3/wild/-94,35,11",
    ]));
    setArea(1, -95, 35, 9);
    // setMob(random(3), 3, 0);
    set("objects", ([
        WORLD_9_DIR "1/npc/guard": 2,
    ]) );
    setup();
}

int valid_leave(object me, string dir)
{
    if(dir == "eastup" && !me->query_quest_finish("BOSS01"))
    {
        write(HIC "守卫拦住了你并说道：“如果你确定要离开这里，请证明你有冒险的勇气。”\n" NOR);
        write(HIY "提示：你需要完成守卫的任务才能离开，如果还没有接受任务，请输入[ask g]\n" NOR);
        return 0;
    }
    else
        return ::valid_leave(me, dir);
}
