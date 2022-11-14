#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    int id;
    object ob;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： new /path/filename\n" NOR);
    }
    if (ob = new(arg))
    {
        sscanf(file_name(ob), "%*s#%s", id);
        write(HIG "新对象 " + arg + " 的编号是 " + id + "\n" NOR);
    }
    else
    {
        write(HIR + arg + "载入失败！\n" NOR);
    }

    return 1;
}
