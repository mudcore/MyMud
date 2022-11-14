// drop.c

#include <ansi.h>
inherit _CLEAN_UP;

int do_drop(object me, object obj);

int main(object me, string arg)
{
    object obj;
    mixed info;

    if (!arg)
        return notify_fail("你要丢下什么东西？\n");

    if (!objectp(obj = present(arg, me)))
        return notify_fail("你身上没有这样东西。\n");

    if (info = obj->query_temp("equipped"))
        return notify_fail("请先脱下装备再丢吧。\n");

    if (info = obj->query("no_drop"))
        return notify_fail(stringp(info) ? info + "\n" : "这样东西不能随意丢弃。\n");

    if (me->is_busy())
    {
        return notify_fail("你现在正忙着呢。\n");
    }

    if (me->is_fighting())
    {
        me->start_busy(1);
        return notify_fail("你正在战斗中，先专心把敌人解决了吧。\n");
    }

    return do_drop(me, obj);
}

int do_drop(object me, object ob)
{
    string msg;
    object obj;

    if (ob->query_temp("amount") > 1)
    {
        ob->add_amount(-1);
        obj = new (base_name(ob));
    }
    else
        obj = ob;

    if (environment(me)->is_area())
    {
        if (!area_move_side(obj, me))
            return notify_fail("你啥也没有丢掉 T_T\n");
    }
    else if (!obj->move(environment(me)))
    {
        return notify_fail("你啥也没有丢掉 T_T\n");
    }

    msg = sprintf("$ME丢下一%s%s。", obj->query("unit") ? obj->query("unit") : "个", obj->name());
    msg("vision", msg, me);
    if (!obj->is_character() && !obj->query("value"))
    {
        write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
        destruct(obj);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : drop [sth]

这个指令可以让你丢弃不要的物品。

HELP );
    return 1;
}
