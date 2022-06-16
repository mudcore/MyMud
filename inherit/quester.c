/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: quester.c
Description: 任务触发
Author: xuefeng
Version: v1.0
Date: 2020-01-17
*****************************************************************************/
int is_quester()
{
    return 1;
}

// 接受任务
int ask_quest(object me)
{
    return QUEST_D->ask_quest(this_object(), me);
}

// 完成任务
int complete_quest(object me)
{
    return QUEST_D->complete_quest(this_object(), me);
}
