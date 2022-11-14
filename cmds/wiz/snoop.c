// snoop.c

#include <ansi.h>

inherit _CLEAN_UP;

int main(object me, string arg)
{
    string msg;
    object sob;
    object ob;

    if (!wizardp(me))
        return 0;

    if (!interactive(me))
        return 0;

    if (!arg)
    {
        if (objectp(ob = query_snooping(me)))
            write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
        else
            write("你现在没有监听任何人。\n");

        return 1;
    }
    else if (arg == "-d")
    {
        snoop(me);
        write("Ok.\n");
        return 1;
    }
    else if (sscanf(arg, "-i %s", arg) || arg == "-i")
    {
        if (arg == "-i")
            ob = me;
        else
            ob = find_player(arg);
        if (!objectp(ob))
        {
            write("没有找到 " + arg + " 这个玩家，无法查看信息。\n");
            return 1;
        }

        msg = "目前有关" + ob->short() + "的监听情况如下：\n";
        if (objectp(sob = query_snooping(ob)))
            msg += "正在监听" + sob->short() + "收到的信息。\n";
        else
            msg += "没有监听任何人。\n";

        if (objectp(sob = query_snoop(ob)))
            msg += "正在被" + sob->short() + "窃听。\n";
        else
            msg += "没有被任何人窃听。\n";

        write(msg);
        return 1;
    }

    ob = find_player(arg);
    if (!ob)
        ob = find_living(arg);
    if (!ob)
        return notify_fail("没有这个人。\n");

    if (!interactive(ob))
        return notify_fail("这个玩家不在线上，无法监听。\n");

    if (me == ob)
        return notify_fail("请用 snoop -d 解除监听。\n");

    snoop(me, ob);
    write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");
    if (userp(ob))
        log_file("snoop",
                 sprintf("%-10s - %-10s snoops %-10s on %s.\n", me->short(), query_ip_number(ob), ob->short(),
                         ctime(time())));

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@TEXT
指令格式：snoop <某人> | -d | -i <某人>

监听其他使用者所收听的讯息，snoop -d 则取消监听。

使用 -i 参数可以查看某人目前窃听的信息。
TEXT );
    return 1;
}
