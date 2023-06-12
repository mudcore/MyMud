// 标准室内环境模板STD_ROOM
inherit _ROOM;

void create()
{
    set("short", "虚空");
    set("long", "这里是虚幻时空，四周雾蒙蒙一片，什么也看不清。");
    set("dq", 0); // 设置所属世界
    set("outdoors", 0); // 设置是否户外
    setArea(0, 0, 0, 0); // 设置所属地区和x,y,z坐标
    set("no_get", 0); // 是否禁止拾起
    set("no_drop", 0); // 是否禁止丢弃
    set("no_fight", 1); // 是否禁止战斗
}
