#include <ansi.h>
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", "沃尔罗村郊外路口");
    set("long", "这里是沃尔罗村郊外，西方是一条绵长的山沟，东北有一个湖泊，湖边绿树成荫，路边竖着一个路标("HIY"board"NOR")。");
    set("exits", ([
        "north" : __DIR__"-125,21,9",
        "south" : __DIR__"-125,19,9",
        "west" : __DIR__"-126,20,9",
        "east" : __DIR__"-124,20,9",
    ]));
    set("item_desc", ([
        "board": "
                    圣修塔因城方向(-95,35,9)↗\n
    ↖沃尔罗村(-130,29,9)\n
            基萨格纳遗迹入口(-105,15,9)↘\n",
    ]));
    setArea(1, -125, 20, 9);
    // setMob(random(2), 2, 0);
}
