#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    string msg, str1, str2;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： set_living_name /path/target name\n" NOR);
    }
    sscanf(arg, "%s %s", str1, str2);
    if (str2)
    {
        if (!(ob = load_object(str1)))
        {
            return notify_fail(HIR "没有找到对象 " + str1 + "\n" NOR);
        }
        msg = HIG "对象 " + str1 + " 取名为：" + str2 + "\n" NOR;
    }
    else
    {
        ob = me;
        str2 = arg;
        msg = HIG "你的名字改为：" + arg + "\n" NOR;
    }

    fun = bind((: set_living_name :), ob);
    evaluate(fun, str2);
    write(msg);

    return 1;
}
