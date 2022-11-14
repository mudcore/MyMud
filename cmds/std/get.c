// Filename : /cmds/get.c

#include <ansi.h>
inherit _CLEAN_UP;

int do_get(object me, object ob);

int main(object me, string arg)
{
    object obj;
    mixed info;

    if (!arg) return notify_fail("你要捡起什麽东西？\n");

    if (!objectp(obj = present(arg, environment(me))))
        return notify_fail("你附近没有这样东西。\n");

    if (info = obj->query("no_get")) {
        return notify_fail(stringp(info) ? info : "这个东西拿不起来。\n");
    }

    if (me->is_busy()) {
        return notify_fail("你现在正忙着呢。\n");
    }

    if (me->is_fighting()) {
        me->start_busy(1);
        return notify_fail("你正在战斗中，先专心把敌人解决了吧。\n");
    }

    if (obj == me) return notify_fail("你想的真棒，可惜你没这个能耐~ T_T！\n");

    if (userp(obj)) {
        return notify_fail("你想劫财还是劫色？\n");
    }

    return do_get(me, obj);
}

int do_get(object me, object ob)
{
    object obj;
    string msg;

    if (ob->query_temp("amount") > 1){
        ob->add_amount(-1);
        obj = new(base_name(ob));
    } else obj = ob;

    if (obj->move(me))
    {
        msg = sprintf("$ME捡起一%s%s。", obj->query("unit")? obj->query("unit") : "个", obj->name());
        msg("vision", msg, me);
        return 1;
    }
    else
        return notify_fail("你啥也没有捡起来 T_T\n");
}

int help(object me)
{
    write(@HELP
指令格式 : get [sth]

这个指令可以让你捡起地上的物品。

HELP );
    return 1;
}
