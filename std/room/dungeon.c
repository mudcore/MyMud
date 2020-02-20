// 标准地牢环境模板STD_DUNGEON
inherit STD_WILD;

protected void create()
{
    set("short", "阿蒙陵寝");
    set("long",@LONG
这里是天使之王阿蒙隐藏在贝克兰德郊外的地下陵寝，大量被污染的魔物和失控成怪物的冒险者躲在里面。
LONG);
    set("outdoors", 0); // 设置是否户外
}
