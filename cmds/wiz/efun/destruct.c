#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        // destruct(this_object());
        return notify_fail(HIY "指令格式： destruct /path/target\n" NOR);
    }
    else if (ob = find_object(arg))
    {
        destruct(ob);
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}
