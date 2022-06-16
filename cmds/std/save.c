#include <ansi.h>

int main(object me, string arg)
{
    // 保存个人数据
    if (me->save())
    {
        if (nullp(arg))
        {
            write(GRN "你截止目前的事迹已被历史铭记 o(^▽^)o\n" NOR);
        }
    }
    else
        write(RED "【系统】档案存储失败 T_T\n" NOR);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : save

这个指令可以让你主动保存个人游戏资料。

HELP );
    return 1;
}
