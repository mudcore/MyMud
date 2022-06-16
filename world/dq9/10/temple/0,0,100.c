/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: church.c
Description: 达玛神殿
Author: xuefeng
Version: v1.0
*****************************************************************************/
inherit STD_CHURCH;

private void create()
{
    ::create();
    set("short", "达玛神殿");
    set("long", "这里是达玛神殿的转职之间，冒险者们可以在这里找达玛神官转职和转生。");
    setArea(10, 0, 0, 100);
    set("exits", ([
        "south" : __DIR__"0,-1,100",
        "north" : __DIR__"0,1,100",
        "west" : __DIR__"-1,0,100",
        "east" : __DIR__"1,0,100",
    ]));
    set("objects", ([
        WORLD_9_DIR "10/npc/divine_officer": 1,
    ]) );
    setup();
}
