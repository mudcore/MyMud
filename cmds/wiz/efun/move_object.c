#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    string msg, str1, str2;
    object ob1, ob2;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： move_object /path/target 或者 move_object /path/ob1 to /path/ob2\n" NOR);
    }

    sscanf(arg, "%s to %s", str1, str2);

    if (str2)
    {
        if (!(ob1 = load_object(str1)))
        {
            return notify_fail(HIR "没有找到对象 " + str1 + "\n" NOR);
        }

        if (!(ob2 = load_object(str2)))
        {
            return notify_fail(HIR "没有找到对象 " + str2 + "\n" NOR);
        }
        msg = HIG "对象 " + str1 + " 的当前环境：" + str2 + "\n" NOR;
    }
    else
    {
        if (!(ob2 = load_object(arg)))
        {
            return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
        }
        ob1 = me;
        msg = HIG "你的当前环境：" + arg + "\n" NOR;
    }

    fun = bind((: move_object :), ob1);
    evaluate(fun, ob2);
    write(msg);

    return 1;
}
