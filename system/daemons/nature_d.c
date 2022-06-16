/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: nature_d.c
Description: 自然天气系统守护进程
Author: xuefeng
Version: v1.0
Date: 2020-04-21
*****************************************************************************/
#include <ansi.h>

inherit CORE_NATURE_D;

// todo 光线系统，魔物活动时间

void event_dawn(object file)
{
    // debug("event_dawn : " + file);
}

void event_sunrise(object file)
{
    // debug("event_sunrise : " + file);
    message("vision", "【注意】" HIC "天亮了，夜间活动的魔物都躲了起来。" NOR, users());
}

void event_morning(object file)
{
    // debug("event_morning : " + file);
}

void event_noon(object file)
{
    // debug("event_noon : " + file);
}

void event_afternoon(object file)
{
    // debug("event_afternoon : " + file);
}

void event_evening(object file)
{
    // debug("event_evening : " + file);
    message("vision", "【警告】" HIR "马上要到晚上了，夜间活动的魔物开始出没。" NOR, users());
}

void event_night(object file)
{
    // debug("event_night : " + file);
}
