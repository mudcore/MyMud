inherit _CLEAN_UP;

int main(object me, string arg)
{
    object obj;
    string err;
    string file;
    int amount;

    if (!wizardp(me))
        return 0;

    if (!arg || sscanf(arg, "%s %d", file, amount) != 2)
    {
        file = arg;
        amount = 1;
    }
    amount = abs(amount);

    if (!file)
        file = me->query("cwf");
    if (!file)
        return notify_fail("你要复制啥？\n");

    file = resolve_path(me->query("cwd"), file);
    if (sscanf(file, "%*s.c") != 1)
        file += ".c";
    me->set("cwf", file);

    if (!find_object(file))
    {
        err = catch (call_other(file, "???"));
        if (err)
        {
            write("载入失败：" + err + "\n");
            return 1;
        }
    }

    err = catch (obj = new (file));
    if (err)
    {
        write("复制失败：" + err + "\n");
        return 1;
    }

    if (!objectp(obj))
    {
        write("你无法复制该对象。\n");
        return 1;
    }

    log_file("static/clone", sprintf("%s %-9s clone %s(%d)\n",
                                     log_time(), geteuid(me),
                                     base_name(obj), amount));
    if (!obj->is_character() && !obj->query("no_get") && obj->move(me))
    {
        write(obj->name() + "复制成功，放在你的物品栏。\n");
    }
    else if (obj->move(environment(me)))
    {
        write(obj->name() + "复制成功，放在这个房间。\n");
    }
    else
    {
        destruct(obj);
        return notify_fail("无法复制不能移动的对象(" + file + ")。\n");
    }

    if (amount > 10)
        amount = 10;
    while (--amount > 0)
    {
        obj = new (file);
        if (!objectp(obj))
            continue;

        if (obj->is_character() || obj->query("no_get") || !obj->move(me))
            obj->move(environment(me));
    }

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : clone <文件名> [<数量>]

利用此指令可复制任何能移动之对象(含人物)。

HELP );
    return 1;
}
