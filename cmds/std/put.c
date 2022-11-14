inherit _CLEAN_UP;

int do_put(object me, object obj, object dest);

int main(object me, string arg)
{
    string target, item;
    object obj, dest;

    if (! arg) return notify_fail("你要将什么东西放进哪里？\n");

    if (sscanf(arg, "%s in %s", item, target) != 2)
            return notify_fail("你要放什么东西？\n");

    dest = present(target, me);
    if (! dest || living(dest))
        dest = present(target, environment(me));

    if (! dest || living(dest))
        return notify_fail("这里没有这样东西。\n");

    if (! objectp(obj = present(item, me)))
            return notify_fail("你身上没有这样东西。\n");

    return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
    if (! dest->is_container())
    {
        tell_object(me, dest->name() + "不是容器，你不能把东西放进去。\n");
        return 1;
    }

    if (userp(obj))
    {
        tell_object(me, "你无法把" + obj->name() + "塞进去。\n");
        return 1;
    }

    if (obj == dest)
    {
        tell_object(me, "嗯... 自己套自己，你的想法比较有趣。\n");
        return 1;
    }

    if (obj->move(dest))
    {
        msg("vision", sprintf("$ME将一%s%s放进%s。", obj->query("unit"), obj->name(), dest->name()), me);
        return 1;
    }

    return 0;
}

int help()
{
    write(@HELP
指令格式 : put <物品名称> in <某容器>

这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。

HELP
    );
    return 1;
}
