#include <ansi.h>

inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    mapping my;

    if (!wizardp(me))
        return 0;

    if (!arg)
        ob = me;
    else
    {
        ob = present(arg, environment(me));
        if (!ob)
            ob = find_player(arg);
        if (!ob)
            ob = find_living(arg);
    }

    if (!ob)
        return notify_fail("你要恢复谁的状态？\n");

    my = ob->query_entire_dbase();
    my["attr"]["hp"] = ob->query_max_hp();
    my["attr"]["mp"] = ob->query_max_mp();

    // if (me == ob)
    // {
    //     if (me->is_ghost()) me->reincarnate();
    //     me->clear_condition();
    // } else
    // {
    //     if (! living(ob)) ob->revive();
    //     if (ob->is_ghost()) ob->reincarnate();
    //     ob->clear_condition();
    // }
    write("OK!\n");
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : recover <对象名称>

这个指令可以恢复你或指定对象(含怪物)。

HELP );
        return 1;
}
