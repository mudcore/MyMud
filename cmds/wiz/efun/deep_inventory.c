#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        print_r(deep_inventory(me));
    }
    else if (ob = load_object(arg))
    {
        print_r(deep_inventory(ob));
    }
    else
    {
        return notify_fail(HIR "没有找到对象 " + arg + "\n" NOR);
    }

    return 1;
}
