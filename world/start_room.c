/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: start_room.c
Description: 神灵护佑的地方，新玩家的降生之地
Author: xuefeng
Version: v1.0
*****************************************************************************/

#include <ansi.h>

inherit STD_ROOM;

varargs private void create(int x, int y, int z)
{
    set("short", "天使界");
    set("no_fight", 1);
    set("exits", ([
        "up" : __DIR__ "start_room/" + x + "," + y + "," + (z + 1),
        "north" : __DIR__ "start_room/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "start_room/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "start_room/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "start_room/" + (x + 1) + "," + y + "," + z,
    ]));
    if (!x && !y && !z)
    {
        set("long", HIW "这里是天使界的中心，你可以随时回到这里(指令：" HIY "home" HIW ")，这里还有一块闪闪发光的水晶屏幕，显示着一些信息(指令：" HIY "l screen" HIW ")。" NOR);
        // addExit("down", __DIR__"dq9/1/village/-130,32,10");
        addExit("down", ([
            "filename" : WORLD_9_DIR "1/village",
            "x_axis" : 25,
            "y_axis" : 15,
        ]));
        set("item_desc", ([
            "screen":"\n新手指南：" HIY "(help newbie)" NOR "\n新手指北：" HIY "(help tutorial)" NOR "\n进入世界：" HIY "(down)\n" NOR
        ]));
        set("objects", ([
            WORLD_DIR "npc/ivy": 1,
        ]) );
        setup();
    }
    else
    {
        set("long", HIW "这里是位于星空深处的天使界，是守护世界的天使们居住的地方，据说女神就在天使界的某地沉睡。" NOR);
        if (!random(100))
        {
            set("objects", ([
                ITEM_DIR "hot_spring": 1,
            ]) );
            setup();
        }
    }
    if (z > 0)
    {
        set("exits/down", __DIR__ "start_room/" + x + "," + y + "," + (z - 1));
    }
    if (z == 99)
    {
        removeExit("up");
    }

    setArea(0, x, y, z);
    // setup();
    // replace_program(ROOM);
}

void init()
{
    object me = this_player();

    if (!me->in_condition(CD_BLESSING))
    {
        me->start_condition(CD_BLESSING);
    }
}

void virtual_start()
{
    if (!random(3))
    {
        set("objects", ([
            WORLD_DIR "npc/angel":random(3),
        ]));
    }

    setup();
}
