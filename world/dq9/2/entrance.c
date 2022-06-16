/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: entrance.c
Description: 基萨格纳遗迹入口，新手试炼任务地区
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit STD_WILD_9;

private void create()
{
    ::create();
    set("short", "基萨格纳遗迹入口");
    set("long", "这里是基萨格纳遗迹入口，遗迹里面有魔物出没，危险重重。");
    set("exits", ([
        "up" : WORLD_9_DIR "1/wild/-105,15,9",
        // "enter" : __DIR__ "dungeon/-105,15,6",
        "enter" : __DIR__ "maze1/entry",
    ]));
    setArea(2, -105, 15, 8);
    setMob(0, 0, 0);
    // set("no_fight", 1);
    set("objects", ([
        WORLD_9_DIR "2/npc/adventurer": 1,
        WORLD_9_DIR "npc/hunter": 1,
    ]) );
    setup();
}
