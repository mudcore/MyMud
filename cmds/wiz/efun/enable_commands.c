#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： enable_commands /path/target\n" NOR);
    }

    if (!(ob = load_object(arg)))
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    fun = bind((: enable_commands :), ob);
    evaluate(fun, 0);
    tell_object(me, HIG "对象 " + arg + " 成为生物。\n" NOR);

    return 1;
}
