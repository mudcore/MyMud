/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: room.c
Description: 游戏房间环境（安全区）标准继承对象 STD_ROOM
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit _ROOM;

void create()
{
    set("short", "虚空");
    set("long", "这里是虚幻时空，四周雾蒙蒙一片，什么也看不清。");
    set("dq", 0); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(0, 0, 0, 0); // 设置所属地区和x,y,z坐标
    setMob(0, 0, 0); // 设置怪物种类、每种数量上限和等级范围（全部：0、低级：1、中级：2、高级：3）
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
}
