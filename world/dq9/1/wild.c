#include <ansi.h>

inherit STD_WILD_9;

nosave int max_north = 35;
nosave int max_south = 5;
nosave int max_east = -95;
nosave int max_west = -135;

void setEntry(int x, int y, int z);

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", HIG "沃尔罗村郊外" NOR);
    set("long", "这里是沃尔罗村郊外，放眼看去有绿油油的草地、起伏的山坡和茂密的树林，让人心旷神怡，不过要小心随时可能冒出来的魔物。");
    setArea(1, x, y, z);
    setMob(random(3), random(4), random(7));

    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));

    if (y == max_south)
    {
        removeExit("south");
        set("long", "这里是沃尔罗村郊外山谷，高高的大山挡住了向南通行的路，据说在山的那一边也有村落。");
    }
    if (y == max_north)
    {
        removeExit("north");
        set("long", "这里是沃尔罗村郊外山路，据说山的那一边就是大海，但是从这里翻不过去，沿着山路一路向东可以到达圣修塔因城方向。");
    }
    if (x == max_west)
    {
        removeExit("west");
        set("long", "这里是沃尔罗村郊外山谷，据说山的那一边就是大海，但是从这里翻不过去。");
    }
    if (x == max_east)
    {
        removeExit("east");
        set("long", "这里是沃尔罗村郊外山谷，山的那一边就是圣修塔因城区域，但是从这里翻不过去。");
    }
    // 随机指示
    if (!random(20))
    {
        set("long", "这里是沃尔罗村郊外荒路，路边有一块指示牌("HIY"board"NOR")指示着方向。");
        switch (random(4))
        {
        case 1:
            set("item_desc", ([
                "board" : "圣修塔因城方向：" HIY "(-95,35)" NOR "\n"
            ]));
            break;
        case 2:
            set("item_desc", ([
                "board" : "基萨格纳遗迹：" HIY "(-105,15)" NOR "\n"
            ]));
            break;
        default:
            set("item_desc", ([
                "board" : "沃尔罗村：" HIY "(-130,30)" NOR "\n"
            ]));
            break;
        }
    }
    // 村庄
    if (y == 29 && x >= -135 && x <= -125)
    {
        set("long", "这里是沃尔罗村郊外，北边就是村庄，高高的围墙防护着村庄被魔物袭击。");
        removeExit("north");
    }
    if (x == -124 && y >= 30 && y <= 35)
    {
        set("long", "这里是沃尔罗村郊外，西边就是村庄，高高的围墙防护着村庄被魔物袭击，需要绕过南边的湖泊才能到村口。");
        removeExit("west");
    }
    // 村庄入口
    if (x == -130 && y == 29 && z == 9)
        setEntry(x, y, z);

    // 村外地形：山谷和湖泊
    if (x >= -135 && x < -125 && y == 20)
    {
        removeExit("south");
        removeExit("north");
    }
    if (x > -125 && x < -115 && y == 20)
    {
        set("long", "这里是沃尔罗村郊外的湖畔南岸，清澈的湖水随着微风荡漾起一圈又一圈的涟漪。");
        removeExit("north");
    }
    if (x > -125 && x < -115 && y == 30)
    {
        set("long", "这里是沃尔罗村郊外的湖畔北岸，清澈的湖水随着微风荡漾起一圈又一圈的涟漪。");
        removeExit("south");
    }
    if (x == -125 && y > 20 && y < 30)
    {
        set("long", "这里是沃尔罗村郊外的湖畔西岸，清澈的湖水随着微风荡漾起一圈又一圈的涟漪。");
        removeExit("east");
    }
    if (x == -115 && y > 20 && y < 30)
    {
        set("long", "这里是沃尔罗村郊外的湖畔东岸，清澈的湖水随着微风荡漾起一圈又一圈的涟漪。");
        removeExit("west");
    }
}

/**
 * 设置入口
 */
void setEntry(int x, int y, int z)
{
    set("short", "沃尔罗村口郊外");
    set("long", "这里是沃尔罗村口的郊外，向北就进入由天使艾薇(ivy)守护着的沃尔罗村了。");
    set("exits", ([
        "enter" : ([
            "filename" : WORLD_9_DIR "1/village",
            "x_axis" : 25,
            "y_axis" : 23,
        ]),
        "south":__DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));
    setMob(random(2), 1, 1);
}
