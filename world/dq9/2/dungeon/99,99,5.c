#include <ansi.h>

inherit STD_DUNGEON_9;

private void create()
{
    ::create();
    set("short", HIR "试炼之间" NOR);
    set("long", "这里是基萨格纳遗迹的试炼之间，冒险者证明自己勇气的地方。");
    setArea(2, 99, 99, 5);
    setMob(0, 0, 0);
    set("exits", ([
        "out" : WORLD_9_DIR "2/entrance",
    ]));
    set("objects", ([
        MOB_DIR "9/257": 1,
    ]) );
    setup();
}

int valid_leave(object me, string dir)
{
    object *ob = filter_array(all_inventory(), (: $1->is_mob() :));
    // print_r(ob);
    if (dir == "out" && sizeof(ob))
    {
        write(HIR "你必须击败这里的魔物才能离开！\n" NOR);
        return 0;
    }
    me->set_temp("BOSS1", 1);
    return ::valid_leave(me, dir);
}
