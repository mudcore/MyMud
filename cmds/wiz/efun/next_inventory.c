#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        write(next_inventory(me) + "\n");
    }
    else if (ob = load_object(arg))
    {
        write(next_inventory(ob) + "\n");
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}
