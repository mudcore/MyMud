// goto.c
#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    int goto_inventory = 0;
    object obj;
    string msg;

    if (!wizardp(me))
        return 0;

    if (!arg)
        return notify_fail("你要去哪里？\n");

    if (sscanf(arg, "-i %s", arg))
        goto_inventory = 1;

    obj = find_player(arg);
    if (!obj)
        obj = find_living(arg);
    if (!obj)
    {
        arg = resolve_path(me->query("cwd"), arg);

        if (!(obj = load_object(arg)))
        {
            return notify_fail("没有这个玩家、生物或地方。\n");
        }
    }

    if (!goto_inventory)
    {
        if (environment(obj))
            obj = environment(obj);
        else
        {
            if (obj->is_character())
                obj = 0;
        }
    }

    if (!obj)
        return notify_fail("目标位置锁定失败。\n");

    if (environment(me) == obj)
        return notify_fail("你好像已经在目的地啦~\n");

    if (obj == me)
        return notify_fail("你的目标位置好像就是自己？\n");

    if (me->query("gender") == "女性")
        tell_object(me, HIM "你化作彩虹而去。\n" NOR);
    else
        tell_object(me, HIG "你化作清风而去。\n" NOR);

    if (!me->move(obj))
    {
        msg = HIM "你的遁术失败了。\n" NOR;
    }
    else
    {
        msg = HIW "你到了地方，落下遁光，收住身形。\n" NOR;
    }

    tell_object(me, msg);

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : goto [-i] <目标>

这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.

HELP );
    return 1;
}
