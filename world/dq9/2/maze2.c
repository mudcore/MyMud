// 迷宫
#include <ansi.h>
inherit CORE_VRM;

void create()
{
    //迷宫房间所继承的对象的档案名称
    set_inherit_room( STD_DUNGEON_9 );

    //迷宫房间里的怪物
    // set_maze_npcs(({MOB_DIR "9/11", MOB_DIR "9/28", MOB_DIR "9/38", MOB_DIR "9/44", MOB_DIR "9/55"}));

    //迷宫的单边长
    set_maze_long(10);

    //入口方向(出口在对面)
    set_entry_dir("south");

    //入口与区域的连接方向
    set_link_entry_dir("up");

    //入口与区域的连接档案名
    set_link_entry_room(__DIR__"dungeon/-55,-5,6");

    //出口与区域的连接方向
    set_link_exit_dir("enter");

    //出口与区域的连接档案名
    set_link_exit_room(__DIR__"dungeon/99,99,5");

    //入口房间短描述
    set_entry_short(HIC "基萨格纳遗迹" NOR);

    //入口房间描述
    set_entry_desc(HIB @LONG
这里是基萨格纳遗迹，到处都是断壁残垣，魔物潜藏在里面等待着猎物，这里向上是冒险者的转职之间，向前可到遗迹深处。
LONG NOR);

    //出口房间短描述
    set_exit_short(HIC "基萨格纳遗迹" NOR);

    //出口房间描述
    set_exit_desc(HIB @LONG
这里是基萨格纳遗迹，到处都是断壁残垣，向北方向的是一座巨大的牢笼，里面封印着强大的魔物。
LONG NOR);

    //迷宫房间的短描述
    set_maze_room_short(HIB "基萨格纳遗迹下层" NOR);

    //迷宫房间的描述，如果有多条描述，制造每个房间的时候会从中随机选择一个。
    set_maze_room_desc(HIB @LONG
这里是基萨格纳遗迹下层，到处都是断壁残垣，魔物潜藏在里面等待着猎物，据说在遗迹深处封印着强大的魔物。
LONG NOR);

    // 迷宫房间是否为户外房间？
    // set_outdoors(1);

    // 是否绘制迷宫地图?
    set_maze_map(1);

    // 迷宫的额外参数
    set_extra_info(([
        "area" : 2,
        "zone/z" : 1,
        "mob" : 3,
        "mob_max" : 4,
        "mob_range" : 6,
    ]));
}
