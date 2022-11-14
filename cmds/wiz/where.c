inherit _CLEAN_UP;

int main(object me, string str)
{
    object ob, where;

    if (!wizardp(me))
        return 0;

    if (!str)
        return notify_fail("指令格式：where <人物或档名>\n");

    ob = find_player(str);
    if (!ob)
        ob = find_living(str);
    if (!ob)
        ob = find_object(str);
    if (!ob)
        return notify_fail("没有找到这个人。\n");

    where = environment(ob);
    if (!where)
        return notify_fail("这个人不知道在哪里...\n");

    write(sprintf("%s现在在%s(%s).\n",
                  (string)ob->short(),
                  (string)where->short(),
                  (string)file_name(where)));
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : where <对象名称>

这个指令可以查找对象在哪儿。

HELP );
    return 1;
}
