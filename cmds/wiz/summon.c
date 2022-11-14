inherit _CLEAN_UP;

int main(object me, string str)
{
    object ob, where, env = environment(me);

    if (!wizardp(me))
        return 0;

    if (!str)
        return notify_fail("指令格式：summon <人物或档名>\n");

    ob = find_player(str);
    if (!ob)
        ob = find_living(str);
    if (!ob)
        ob = find_object(str);
    if (!ob)
        return notify_fail("没有找到这个人或对象。\n");

    where = environment(ob);
    if (where == env)
        return notify_fail("你要召唤的对象近在眼前哦。\n");
    if (where == me)
        return notify_fail("你要召唤的对象就在你身上哦。\n");

    msg("warning", "$ME的脚下突然出现了传送阵，随着光芒闪耀，$ME被传送走了。", ob);
    ob->move(env);
    msg("info", "一道光芒闪耀，$ME出现在大家的眼前。", ob);

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : summon <对象名称>

这个指令可以召唤神龙。

HELP );
    return 1;
}
