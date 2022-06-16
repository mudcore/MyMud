#include <ansi.h>

inherit STD_WILD_8;

void setEntry(int x, int y, int z);

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", HIG "托拉佩塔郊外" NOR);
    set("long", "这里是托拉佩塔城的郊外，放眼看去绿油油的草地，让人心旷神怡，不过要小心潜藏草丛中的魔物。");
    setArea(1, x, y, z);
    setMob(random(3), random(4), random(7));

    set("exits", ([
        "north" : __DIR__ "wild/" + x + "," + (y + 1) + "," + z,
        "south" : __DIR__ "wild/" + x + "," + (y - 1) + "," + z,
        "west" : __DIR__ "wild/" + (x - 1) + "," + y + "," + z,
        "east" : __DIR__ "wild/" + (x + 1) + "," + y + "," + z,
    ]));
    // 随机关闭一个出口
    if (!random(7))
    {
        removeRandomExit();
        // 随机关闭第二个出口
        if (!random(3))
        {
            removeRandomExit();
        }
    }

    // 村庄入口
    if (x == 3 && y == 14 && z == 9)
        setEntry(x, y, z);
}

void setEntry(int x, int y, int z)
{
    set("short", HIG "托拉佩塔城门外" NOR);
    set("long", "这里是托拉佩塔城的郊外，北边就是雄伟壮观的托拉佩塔城。");
    set("exits", ([
        "enter" : __DIR__ "gate",
        "south" : __DIR__ "wild/3,13,9",
        "west" : __DIR__ "wild/2,14,9",
        "east" : __DIR__ "wild/4,14,9"]));
    set("mob", random(2));
    set("mob_max", 1);
    set("mob_range", 1);
}
