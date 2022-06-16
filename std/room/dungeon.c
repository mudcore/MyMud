/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: dungeon.c
Description: 游戏地牢环境（危险区）继承对象 STD_DUNGEON
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <status.h>

inherit STD_ROOM;

void create()
{
    ::create();
    set("short", "地牢");
    set("long", "这里是废弃地牢，四周雾蒙蒙一片，什么也看不清。");
    set("no_fight", 0);
}

/**
 * 游戏刷新魔物设置
 */

void init()
{
    object me = this_player();
    object ob = next_inventory(me);
    if ( interactive(me) && !me->query_temp(STA_INVISIBLE)
        && query("area") && query("mob")
        && random(me->query_charm()) < random(200)
        && (!objectp(ob) || !living(ob)) )
    {
        set("objects", AREA_D->mob(query("dq"), query("area"),
            query("mob"), query("mob_max"), query("mob_range")));
        setup();
    }
    // 毒气陷阱
    if (query("pitfall"))
    {
        me->start_condition(CD_POISON);
    }
}
