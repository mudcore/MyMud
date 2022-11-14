// kickout.c
inherit _CLEAN_UP;

void kickout_player(object me, object ob);

int main(object me, string arg)
{
    object ob;
    if (!wizardp(me))
        return 0;

    if (!arg)
        return notify_fail("你要踢谁？\n");

    ob = find_player(arg);

    if (!ob)
        return notify_fail("没有找到这个玩家。\n");

    if (ob == me)
        return notify_fail("你确定这样没搞错？\n");

    kickout_player(me, ob);
    return 1;
}

void kickout_player(object me, object ob)
{
    CHANNEL_D->do_channel(me, "msg", sprintf("%s被踢出了游戏。", ob->name()));
    ob->remove();
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : kickout <目标>

管理员踢人指令。

HELP );
    return 1;
}
