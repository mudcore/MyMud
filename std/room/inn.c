/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: inn.c
Description: 每个城镇都有的旅馆 STD_INN
Author: xuefeng
Version: v1.1
Date: 2019-05-19
*****************************************************************************/
#include <ansi.h>

inherit STD_ROOM;

int is_inn() { return 1; }

void create()
{
    ::create();
    set("short", YEL "旅馆" NOR);
    set("long", "这里是托拉佩塔城的旅馆，世界各地的游客路过托拉佩塔城时都会住在这里。");
    set("objects", ([
        STD_MAID:1,
    ]));
    setup();
}

void init()
{
    object ob = this_player();

    if (interactive(ob) && !this_object()->is_fighting() && !ob->in_condition(CD_INN_REVIVE))
    {
        ob->start_condition(CD_INN_REVIVE);
    }
}

/**
 * 离开旅馆清除安逸时光增益
 */
int valid_leave(object me, string dir)
{
    if (dir == "out" && me->in_condition(CD_INN_REVIVE))
    {
        me->stop_condition(CD_INN_REVIVE);
    }
    return ::valid_leave(me, dir);
}
