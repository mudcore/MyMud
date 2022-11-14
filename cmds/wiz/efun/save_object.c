#include <ansi.h>
inherit _CLEAN_UP;

#ifndef __SAVE_GZ_EXTENSION__
#define __SAVE_GZ_EXTENSION__ ".o.gz"
#endif
#define DATA_DIR "/data/"

int main(object me, string arg)
{
    object ob;
    string str, file;
    int i;
    function fun;

    if (!arg || (sscanf(arg, "%s to %s flag %d", str, file, i) != 3))
    {
        return notify_fail(HIY "指令格式： save_object /path/object to save_name flag [00|01|10|11]\n" NOR);
    }

    if (!(ob = load_object(str)))
    {
        return notify_fail(HIR "没有找到对象 " + str + "\n" NOR);
    }

    file = DATA_DIR + file;

    fun = bind((: save_object :), ob);
    if (evaluate(fun, file, i))
    {
        if (i >= 10)
            write(HIG "存档文件：" + file + __SAVE_GZ_EXTENSION__ + "\n" NOR);
        else
            write(HIG "存档文件：" + file + __SAVE_EXTENSION__ + "\n" NOR);
    }

    return 1;
}
