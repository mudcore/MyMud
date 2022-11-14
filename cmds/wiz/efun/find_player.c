#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (!arg)
    {
        return notify_fail(HIY "指令格式： find_player name\n" NOR);
    }
    if (ob = find_player(arg))
        write(HIG + arg + " => " + file_name(ob) + "\n" NOR);
    else
        write(HIR "没有找到名字是 " + arg + " 的玩家！\n" NOR);
    return 1;
}
