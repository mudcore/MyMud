/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: wild.c
Description: 游戏野外环境（危险区）继承对象 STD_WILD
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit STD_DUNGEON;

void create()
{
    ::create();
    set("short", "荒郊野外");
    set("long", "这里是荒郊野外，四周雾蒙蒙一片，什么也看不清。");
    set("outdoors", 1); // 设置是否户外
}
