// 标准地牢环境模板STD_DUNGEON
inherit STD_ROOM;

void create()
{
    ::create();
    set("short", "地牢");
    set("long", "这里是废弃地牢，四周雾蒙蒙一片，什么也看不清。");
    set("no_fight", 0);
}
