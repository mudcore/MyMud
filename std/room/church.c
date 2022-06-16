/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: church.c
Description: 每个城镇都有的教堂 STD_CHURCH
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>

inherit STD_ROOM;

void create()
{
    ::create();
    set("short", HIY "教堂" NOR);
    set("long", "这里是托拉佩塔城的教堂，旅行者可以在这里祈祷获得神灵的帮助。");
    set("objects", ([
       STD_DIVINE : 1,
    ]) );
    setup();
}
