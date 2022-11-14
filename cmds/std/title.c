#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    string msg;
    mapping titles = me->query_titles();
    if (!sizeof(titles))
        return notify_fail(HIM "你还没有获得任何称号哦！\n" NOR);
    if (arg && me->query_title(arg))
    {
        me->set("title", arg);
        write("称号设置成功！\n");
        return 1;
    }

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%|50s| \n", MAG "*" HIY "称号获取记录" NOR MAG "*" NOR);
    msg += " |--------------------------------------------------| \n" NOR;

    foreach (string title in keys(titles))
    {
        msg += sprintf(" |  %-16s%-32s| \n", title, "获得时间：" + log_time(titles[title]));
    }

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    tell_object(me, msg);
    return 1;
}

int help (object me)
{
    write(@HELP
指令格式：title [称号]

查看自己已经获取的称号，并可以使用称号设置自己的头衔。

HELP );
    return 1;
}
