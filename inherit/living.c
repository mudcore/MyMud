/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: char.c
Description: 所有角色父接口 LIVING - 有生命的(living)的对象：玩家／NPC/魔物等
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit _HEART_BEAT;
inherit _COMMAND;
inherit _NAME;
inherit _TEAM;

void create()
{
    seteuid(0); // export_uid
}

// 判断是否是有生命的，包括 disable_living 的角色
int is_character() { return 1; }

// 角色激活
void setup()
{
    seteuid(getuid(this_object()));
    set_heart_beat(1);
    enable_living();
    CHAR_D->setup(this_object());
}

// 从游戏中移除这个角色
void remove()
{
    destruct(this_object());
}

void catch_tell(string message)
{
    // debug_message(this_object() + "-|-" + message);
}
