/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: top.c
Description: 查看玩家排行榜
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>

#define U_ID 0
#define U_NAME 1
#define U_MOBILE 2
#define U_BIRTHDAY 3
#define U_GENDER 4
#define U_TITLE 5
#define U_VOCATION 6
#define U_LV 7
#define U_EXP 8
#define U_COIN 9
#define U_HP 10
#define U_MP 11
#define U_TOWER 12
#define U_KILL 13
#define U_DIE 14
#define U_UPDATED 15

int main(object me, string arg)
{
    int i = 0, top, lv;
    string msg, title;
    mixed data;

    if (member_array(arg, ({"rich", "lv", "exp", "coin", "hp", "mp", "tower", "kill", "die"})) < 0)
    {
        return notify_fail("目前只提供等级(top lv)/经验(top exp)/金钱(top coin)/勇者之塔(top tower)/杀死魔物(top kill)等全服排行。\n");
    }
    if (arg == "rich") arg = "coin";
    switch (arg)
    {
    case "lv":
        top = U_LV;
        title = "当前等级";
        break;
    case "exp":
        top = U_EXP;
        title = "玩家经验";
        break;
    case "coin":
        top = U_COIN;
        title = "金币数量";
        break;
    case "hp":
        top = U_HP;
        title = "生 命 值";
        break;
    case "mp":
        top = U_MP;
        title = "魔 力 值";
        break;
    case "tower":
        top = U_TOWER;
        title = "勇者之塔";
        break;
    case "kill":
        top = U_KILL;
        title = "杀死魔物";
        break;
    case "die":
        top = U_DIE;
        title = "死亡次数";
        break;

    default:
        break;
    }

    if (! wizardp(me) && time() - me->query_temp("last_view") < 10)
        return notify_fail(HIW "排行榜数据更新中，请十秒后再查询。\n" NOR);

    data = CACHE_D->get(arg);

    msg =  HIW "\n                 ┌----『" HIG " 天  梯  榜 " HIW "』----┐\n";
    msg += "|-----------------------------------------------------------|\n";
    msg += "| " HIG "排行" HIW " |    " HIG "姓  名" HIW
           "    | " HIG "  职  业 " HIW " | " HIG " 称    号 " HIW " | " HIG " " + title + " " HIW " |\n";
    msg += "|-----------------------------------------------------------|\n";

    if (!sizeof(data))
    {
        msg += HIW "|        暂时空缺           无                -  |\n" NOR;
    }
    else
        foreach(mixed user in data)
        {
            msg += sprintf(HIW "|" HIG "  %-5d %-15s%|10s %|12s %10d  " HIW "|\n" NOR,
                    ++i,
                    user[1],
                    chinese(user[6]),
                    user[5],
                    user[top]);
            if (user[0] == me->query("id"))
            {
                lv = i;
            }
        }
    msg += HIW "|-----------------------------------------------------------|\n" NOR;

    me->more(msg);
    me->set_temp("last_view", time());
    tell_object(me, "\n" FCC(208) "提示：你的" + title + "在全服排行第 " + lv + " 位。" NOR "\n");
    return 1;

}

int help()
{
    write(@HELP
指令格式 : top [arg]
        top lv      玩家等级排行榜
        top exp     玩家经验排行榜
        top coin    玩家财富排行榜
HELP );
    return 1;
}
