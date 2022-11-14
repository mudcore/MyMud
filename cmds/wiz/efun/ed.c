#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    if (!arg)
    {
        return notify_fail(HIR "指令格式： ed <file> \n" NOR);
    }
    else if (file_size(arg) < 0)
    {
        return notify_fail(HIR "文件 " + arg + " 不存在\n" NOR);
    }
    else
    {
        ed(arg);
    }

    return 1;
}
