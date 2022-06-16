#include <ansi.h>

inherit STD_OUTDOORS;
// (x = -79 || x = -65) && (y == 21 || y == 30) 为城墙区
nosave int max_north = 29;
nosave int max_south = 22;
nosave int max_east = -66;
nosave int max_west = -78;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", HIC "圣修塔因城" NOR);
    set("long", "这里是圣修塔因城，也是最繁华的大都市，居民在王国的守护下安居乐业，城区北部是皇宫，南边是繁华的商业区和居民区。");
    setArea(3, x, y, z);
    set("exits", ([
        "north":__DIR__ "city/" + x + "," + (y + 1) + "," + z,
        "south":__DIR__ "city/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "city/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "city/" + (x + 1) + "," + y + "," + z,
    ]));

    if (y == max_south && x != -72)
    {
        removeExit("south");
        set("long", "这里是圣修塔因城南，南边高大的城墙保护着居民不被魔物袭击。");
    }
    if (y == max_north)
    {
        removeExit("north");
        set("long", "这里是圣修塔因城北，北边高大的城墙保护着居民不被魔物袭击。");
    }
    if (x == max_west)
    {
        removeExit("west");
        set("long", "这里是圣修塔因城西，西边高大的城墙保护着居民不被魔物袭击。");
    }
    if (x == max_east)
    {
        removeExit("east");
        set("long", "这里是圣修塔因城东，东边高大的城墙保护着居民不被魔物袭击。");
    }
    if (y == 27)
    {
        removeExit("north");
        set("long", "这里是圣修塔因王宫外面，不知道出了什么事情，王宫的大门紧闭着，禁止臣民的觐见。");
    }
    if (y == 28)
    {
        removeExit("south");
        set("long", "这里是圣修塔因城王宫内，出宫的大门紧闭着，禁止任何人外出。");
    }
}
