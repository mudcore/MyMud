inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
        return notify_fail("你要使用什么物品？\n");

    if (!objectp(ob = present(arg, me)))
    {
        return notify_fail("你身上没有这样东西。\n");
    }

    if (me->is_busy())
    {
        write("你现在正忙着呢。\n");
        return 1;
    }

    return ob->do_effect(me);
}

int help()
{
    write(@HELP
指令格式 : use <物品>

这个指令可以让你使用物品，如果有效果的话。

HELP );
    return 1;
}
