#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： disable_commands /path/target\n" NOR);
    }

    if (!(ob = load_object(arg)))
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    fun = bind((: disable_commands :), ob);
    evaluate(fun);
    tell_object(me, HIG "对象 " + arg + " 成为非生物对象。\n" NOR);

    return 1;
}
