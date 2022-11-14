#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        write(HIG "你在 " + file_name(environment(me)) + " 中\n" NOR);
    }
    else if (ob = find_object(arg))
    {
        write(HIG "对象 " + arg + " 在 " + file_name(environment(ob)) + " 中\n" NOR);
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}
