/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: wild_8.c
Description: 游戏环境（户外）继承对象 STD_WILD_8
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit STD_WILD;

void create()
{
    ::create();
    set("dq", 8); // 设置所属世界
}
