#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "艾拉菲塔村郊外");
    set("long", "这里是艾拉菲塔村郊外荒野，这里被黑魔法的力量笼罩，进来的冒险者很容易迷失在这里。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(4, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(20))
    {
        set("long", "这里是圣修塔因城郊外荒野，四周有魔物出没。这里有一块指示牌("HIY"board"NOR")。");
        set("item_desc", ([
            "board" : "圣修塔因城方向：" HIY "(-75,41)" NOR "\n"
                      "艾拉菲塔村：" HIY "(-100,80)" NOR "\n"
                      "荒野之森方向：" HIY "(-110,90)" NOR "\n"
        ]));
    }

}
