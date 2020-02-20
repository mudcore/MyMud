// 标准户外环境模板STD_OUTDOORS
inherit STD_ROOM;

protected void create()
{
    ::create();
    set("short", "贝克兰德");
    set("long",@LONG
这里是号称‘希望之地’、‘万都之都’的贝克兰德，但是因为大气污染，城市里有严重的雾霾，也被居民戏称为‘尘埃之都’。
LONG);
    set("outdoors", 1); // 设置是否户外
}
