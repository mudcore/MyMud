/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: outdoors.c
Description: 游戏户外环境（安全区）继承对象 STD_OUTDOORS
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit STD_ROOM;

void create()
{
    ::create();
    set("short", "户外");
    set("long", "这里是户外，阳光明媚，让人感觉心情特别舒畅。");
    set("outdoors", 1); // 设置是否户外
}
