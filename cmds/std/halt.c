// halt.c
#include <ansi.h>

int main(object me, string arg)
{
    if (me->is_busy() && ! intp(me->query_busy()))
    {
        me->interrupt_me(me);
        return 1;
    } else
    if (me->is_fighting())
    {
        return notify_fail(HIW "你现在忙得停不下来。\n" NOR);
    } else
    if (me->is_busy())
        return notify_fail("你现在停不下来。\n");
    else
        return notify_fail("你现在不忙。\n");

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : halt

中止你目前正在做的事情。

HELP );
    return 1;
}
