#include <ansi.h>

#define HELP_DIR "help/"

int help(object me);

int main(object me, string arg)
{
    object file;

    if(!arg)
    {
        arg = "tutorial";
    }

    if (file_size(HELP_DIR + arg) > 0)
    {
        me->more_file(HELP_DIR + arg);
        return 1;
    }
    else if( objectp(file = COMMAND_D->find_command(arg)) ) {
        return file->help(me);
    }
    else
        return notify_fail(HIR "对不起，没有找到相关帮助文档。\n" NOR);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : help [topic]

这个指令可以查看指定主题的帮助说明。

HELP );
    return 1;
}
