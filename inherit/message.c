/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: message.c
Description: 玩家角色信息显示控制接口
Author: xuefeng
Version: v1.0
Date: 2019-03-14
*****************************************************************************/
#include <ansi.h>
#include <attribute.h>
#include <dbase.h>
inherit CORE_MESSAGE;

void receive_message(string type, string str)
{
    // 特定情况屏蔽消息用
    if (query_temp("block_msg/all") || query_temp("block_msg/" + type))
        return;
    // str = break_string(remove_ansi(str), 38);
    switch (type)
    {
    case "info":
        receive(HIC + str + NOR "\n");
        return;
    case "success":
        receive(HIG + str + NOR "\n");
        return;
    case "warning":
        receive(HIY + str + NOR "\n");
        return;
    case "danger":
        receive(HIR + str + NOR "\n");
        return;

    case "magic":
    case "spell":
        receive(HIB "[" + str + "]" NOR "\n");
        return;
    case "skill":
        receive(HIW "[" + str + "]" NOR "\n");
        return;
    case "team":
        receive(HIM + str + NOR "\n");
        return;

    case "outdoor":
        if (environment()->query("outdoors"))
        {
            receive(str + "\n");
        }
        return;

    case "MAP":
        receive(str);
        return;

    case "vision":
        receive(MAG + str + NOR "\n");
        return;
    case "combat":
        receive(CYN + str + NOR "\n");
        return;
    case "RED":
        receive(RED + str + NOR "\n");
        return;
    case "GRN":
        receive(GRN + str + NOR "\n");
        return;
    case "BLU":
        receive(BLU + str + NOR "\n");
        return;
    case "YEL":
        receive(YEL + str + NOR "\n");
        return;

    case "debug":
        receive("\n" BRED "[" + str + "]" NOR "\n");
        return;

    case "chat":
        "/system/daemons/qq_d.c"->send(remove_ansi(str));
    default:
        // debug_message(type);
        receive(str + "\n");
    }
}

void write_prompt()
{
    if (environment()->is_area())
        return;
    write(sprintf("[%s|%s]", GRN + query_hp() + NOR, HIB + query_mp() + NOR));
}
