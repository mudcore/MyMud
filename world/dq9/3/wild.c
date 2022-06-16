#include <ansi.h>

inherit STD_WILD_9;

nosave int max_north = 40;
nosave int max_south = 1;
nosave int max_east = -40;
nosave int max_west = -94;

void setEntry(int x, int y, int z);

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "圣修塔因城郊外");
    set("long", "这里是圣修塔因城郊外荒野，圣修塔因城繁华而安全，是很多冒险者都向往的大都市。");
    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));
    // 随机关闭一个出口
    if (!random(7))
    {
        removeRandomExit();
        // 随机关闭第二个出口
        if (!random(3))
        {
            removeRandomExit();
        }
    }

    setArea(3, x, y, z);
    setMob(random(3), random(4), random(7));

    if (!random(20))
    {
        set("long", "这里是圣修塔因城郊外荒野，四周有魔物出没。这里有一块指示牌("HIY"board"NOR")。");
        set("item_desc", ([
            "board" : "沃尔罗村方向：" HIY "(-95,35)" NOR "\n"
                      "艾拉菲塔村方向：" HIY "(-75,40)" NOR "\n"
                      "贝克塞利亚镇方向：" HIY "(-55,40)" NOR "\n"
        ]));
    }

    if (x > -80 && x < -64 && y == 20)
    {
        set("short", "圣修塔因城外");
        set("long", "这里是圣修塔因城南，高大结实的城墙保护着城内的居民安居乐业。");
        removeExit("north");
    }
    if (x > -80 && x < -64 && y == 31)
    {
        set("short", "圣修塔因城外");
        set("long", "这里是圣修塔因城北，高大结实的城墙保护着城内的居民安居乐业，如果需要进城请到南门。");
        removeExit("south");
    }
    if (x == -80 && y > 20 && y < 31)
    {
        set("short", "圣修塔因城外");
        set("long", "这里是圣修塔因城西，高大结实的城墙保护着城内的居民安居乐业，如果需要进城请到南门。");
        removeExit("east");
    }
    if (x == -64 && y > 20 && y < 31)
    {
        set("short", "圣修塔因城外");
        set("long", "这里是圣修塔因城东，高大结实的城墙保护着城内的居民安居乐业，如果需要进城请到南门。");
        removeExit("west");
    }

    if (y == max_south)
    {
        removeExit("south");
    }
    if (y == max_north)
    {
        removeExit("north");
    }
    if (x == max_west)
    {
        removeExit("west");
    }
    if (x == max_east)
    {
        removeExit("east");
    }

    if (x == -72 && y == 20)
    {
        setEntry(x, y, z);
    }
}

void setEntry(int x, int y, int z)
{
    set("short", BCYN "圣修塔因城门" NOR);
    set("long", "这里是圣修塔因城的城门口，门口的城墙上贴着国王召集冒险者的悬赏告示，这里车水马龙，有大量的冒险者进出城。");
    set("exits", ([
        "enter":__DIR__ "city/" + x + "," + (y + 1) + "," + (z + 1),
        "south":__DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));
    setMob(0, 0, 0);
    set("objects", ([
        WORLD_9_DIR "3/npc/guard": 2,
    ]) );
    setup();
}
