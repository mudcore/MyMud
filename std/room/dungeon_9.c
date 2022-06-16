/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: dungeon_9.c
Description: 游戏环境（地牢）继承对象 STD_DUNGEON_9
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit STD_DUNGEON;

void create()
{
    ::create();
    set("dq", 9); // 设置所属世界
}
