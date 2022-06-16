/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: church.c
Description: 托拉佩塔城的教堂
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
inherit STD_CHURCH;

private void create()
{
    ::create();
    set("exits", ([
        "out" : __DIR__"city2",
    ]));
    set("objects", ([
       __DIR__ "npc/priest" : 1,
    ]) );
    setup();
}
