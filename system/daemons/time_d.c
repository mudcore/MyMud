/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: schedule_d.c
Description: 时间及计划任务系统守护进程
Author: xuefeng
Version: v1.0
Date: 2019-04-01
*****************************************************************************/
inherit CORE_TIME_D;

void create()
{
    mixed *game_crontab = ({
        // "5,25,50 * * * * *", (: debug("game_crontab! " + gametime_digital_clock()) :), "测试任务",
    });
    mixed *real_crontab = ({
        // "* * * * * *", (: debug("real_crontab! " + ctime()) :), "测试任务",
        "*/2 * * * * *", ( : save() :), "存储游戏世界时间",
    });

    ::create();
    set_game_crontab(game_crontab);
    set_real_crontab(real_crontab);
}
