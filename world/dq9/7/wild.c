#include <ansi.h>

inherit STD_WILD_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "东贝克赛利亚郊外");
    set("long", "这里是圣修塔因城东北方向的贝克赛利亚郊外荒野。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    setArea(7, x, y, z);
    setMob(random(3), random(4), random(7));
    if (!random(20))
    {
        set("long", "这里是东贝克赛利亚郊外荒野，四周有魔物出没。这里有一块指示牌("HIY"board"NOR")。");
        set("item_desc", ([
            "board" : "西贝克赛利亚方向：" HIY "(-65,75)" NOR "\n"
                      "贝克赛利亚镇方向：" HIY "(-50,80)" NOR "\n"
                      "圣修塔因城方向：" HIY "(-55,40)" NOR "\n"
        ]));
    }
}
