#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    string msg, str;
    int i;
    function fun;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： set_heart_beat [/path/target] heart_beat_number\n" NOR);
    }
    sscanf(arg, "%s %d", str, i);
    if (i)
    {
        if (!(ob = load_object(str)))
        {
            return notify_fail(HIR "没有找到对象 " + str + "\n" NOR);
        }
        msg = HIG "对象 " + str + " 的心跳设置为 " + i + "\n" NOR;
    }
    else
    {
        ob = me;
        sscanf(arg, "%d", i);
        msg = HIG "你的心跳设置为 " + arg + "\n" NOR;
    }

    fun = bind((: set_heart_beat :), ob);
    evaluate(fun, i);
    write(msg);

    return 1;
}
