/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: quest_d.c
Description: 剧情任务系统守护进程
Author: xuefeng
Date: 2020-02-14
*****************************************************************************/
inherit CORE_QUEST_D;
void create()
{
    doScanQuest();
}

int ask_quest(object who, object me)
{
    if (!doAssign(who, me))
    {
        return notify_fail("对方没有任务需要你的帮助。\n");
    }
}

int complete_quest(object who, object me)
{
    return doReward(who, me);
}
