// 标准野外环境模板STD_WILD
inherit STD_OUTDOORS;

protected void create()
{
    ::create();
    set("short", "神弃之地");
    set("long",@LONG
这里是被众神遗弃的地方，这里的天空没有太阳，没有月亮，没有星星，只有不变的黑夜和撕裂着一切的闪电。
LONG);
    set("no_fight", 0); // 是否禁止战斗
}
