/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: home.c
Description: 新手玩家回到START_ROOM的命令
Author: xuefeng
Version: v1.0
Date: 2020-05-16
*****************************************************************************/
#include <ansi.h>

int main(object me, string arg)
{
    string reborn_room;

    if (me->is_busy())
    {
        return notify_fail("你现在正忙，没法静心向女神祈求。\n");
    }

    if (me->is_fighting())
    {
        me->start_busy(1);
        return notify_fail("你正在战斗中，没法安心向女神祈求。\n");
    }

    if (!strcmp(file_name(environment(me)), START_ROOM))
    {
        return notify_fail("你已经在" + START_ROOM->short() + "了。\n");
    }

    msg("info", "$ME化作流光飞走了～", me);

    if (wizardp(me))
    {
        me->move("wizard/home/gate");
    }
    else if (me->query("lv") > 9)
    {
        if (!(reborn_room = me->query("reborn_room")))
        {
            msg("info", "但是，$ME好像迷路了，又落了下来。", me);
            return notify_fail(RED "你还没有向神父祈祷过，无法返回神父的身边。\n" NOR);
        }
        else if (!strcmp(file_name(environment(me)), reborn_room))
        {
            msg("info", "但是，$ME又落了回来。", me);
            return notify_fail("你已经在" + reborn_room->short() + "了。\n");
        }

        me->move(reborn_room);
    }
    else
    {
        me->move(START_ROOM);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : home

回到月神时空，10级以下玩家可用。

HELP );
    return 1;
}
