#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "迦南帝国");
    set("long", "这里是等待冒险者征服的地区，无数的魔物等待清理。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(35, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(30))
    {
        set("long", "迦南帝国野外，因为魔物的影响，这里变成了一片冒着毒气的沼泽("MAG"bog"NOR")。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }
    else if (!random(40))
    {
        set("long", "这里是迦南帝国野外，这里有一座高耸入云的塔("YEL"tower"NOR")。");
        set("item_desc", ([
            "tower":"封印着魔物的勇者之塔，进去（enter）后只能一层一层挑战，塔内某些层有传送门可离开。\n"
        ]));
        addExit("enter", WORLD_DIR "tower/" + x + "," + y + ",1");
    }
}
