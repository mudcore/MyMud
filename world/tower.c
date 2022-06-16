#include <ansi.h>

inherit STD_DUNGEON_9;

varargs void create(int x, int y, int z)
{
    ::create();
    set("short", "勇者之塔");
    set("long", "这里是勇者之塔第 " + z + " 层，塔内每一层都封印着一种魔物，成为勇者们试练的好地方，很多冒险者都来挑战记录，想成为传说中的勇者。");
    set("exits", ([
        "up":__DIR__ "tower/" + x + "," + y + "," + (z + 1),
    ]));

    if (!random(10))
    {
        set("long", "这里是勇者之塔第 " + z + " 层内部，在这有一座闪耀着白光的传送门，你可以使用它传送出去（out）。");
        addExit("out", START_ROOM);
    }

    setArea(100, x, y, z);
}

/**
 * 游戏刷新魔物设置
 */

void init()
{
    object me = this_player();
    int dq = query("dq"), z = query("zone")["z"], n = 1;

    if (z >= 300)
    {
        n = 1 + random(z / 100);
    }

    if (z && interactive(me))
    {
        set("objects", ([
            MOB_DIR + dq + "/" + abs(z) : n
        ]));
        setup();
    }
}

int valid_leave(object me, string dir)
{
    int storey = me->query("tower"), z = query("zone")["z"];
    object *ob = filter_array(all_inventory(), (: $1->is_mob() :));
    // print_r(ob);
    if (dir == "up" && sizeof(ob))
    {
        write(HIR "你必须清理完当前层的怪物才能离开！\n" NOR);
        return 0;
    }

    if (z > storey)
    {
        me->set("tower", z);
        if (!(z % 10))
        {
            CHANNEL_D->do_channel(this_object(), "msg", sprintf("恭喜 %s 突破勇者之塔第 %d 层。", me->short(), z));
            REWARD_D->bonus(me, z * z);
        }
    }

    return ::valid_leave(me, dir);
}
