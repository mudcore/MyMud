#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "鲁迪亚诺城荒野");
    set("long", "这里是艾拉菲塔村西北方向的荒野，昏暗的环境中充满了危险，大量的魔物隐藏在这里。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    if (!random(20))
    {
        set("long", "这里是荒野之息的森林，因为魔物的影响，这里变成了一片冒着毒气的沼泽("MAG"bog"NOR")。");
        set("pitfall", "bog");
        set("item_desc", ([
            "bog" : HIM "一片冒着毒气的沼泽，如果没有防护直接进来会中毒。\n" NOR,
        ]));
    }
    else if (!random(65))
    {
        set("long", "这里是艾拉菲塔村西北方向的大森林，这里有一座高耸入云的塔("YEL"tower"NOR")。");
        set("item_desc", ([
            "tower":"封印着魔物的勇者之塔，进去（enter）后只能一层一层挑战，塔内某些层有传送门可离开。\n"
        ]));
        addExit("enter", WORLD_DIR "tower/" + x + "," + y + ",1");
    }
    else if (!random(15))
    {
        set("long", "这里是圣修塔因城郊外荒野，四周有魔物出没。这里有一块指示牌("HIY"board"NOR")。");
        set("item_desc", ([
            "board" : "鲁迪亚诺城遗迹：" HIY "(-125,110)" NOR "\n"
                      "艾拉菲塔村方向：" HIY "(-110,90)" NOR "\n"
        ]));
    }
    setArea(5, x, y, z);
    setMob(random(3), random(4), random(7));
}
