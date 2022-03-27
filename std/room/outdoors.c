// 标准户外环境模板STD_OUTDOORS
inherit STD_ROOM;

void create()
{
    ::create();
    set("short", "户外");
    set("long", "这里是户外，阳光明媚，让人感觉心情特别舒畅。");
    set("outdoors", 1); // 设置是否户外
}
