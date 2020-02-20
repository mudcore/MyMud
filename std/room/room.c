// 标准室内环境模板STD_ROOM
inherit ROOM;

protected void create()
{
    set("short", "源堡");
    set("long",@LONG
这里弥漫着朦胧模糊、无边无际的灰雾，灰雾如水流淌，点缀着一颗颗深红色的“星辰”，它们有的很大，有的渺小，有的藏于深处，有的浮在表面。
LONG);
    setArea(0, 0, 0, 0); // 设置所属地区和x,y,z坐标
    set("outdoors", 0); // 设置是否户外
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
    set("exits", ([])); // 设置出口
}
