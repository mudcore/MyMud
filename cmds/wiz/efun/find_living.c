#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： find_living name\n" NOR);
    }
    if (ob = find_living(arg))
        write(HIG + arg + " => " + file_name(ob) + "\n" NOR);
    else
        write(HIR "没有找到名字是 " + arg + " 的对象！\n" NOR);
    return 1;
}
