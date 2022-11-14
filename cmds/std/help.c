#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object file;
    string msg;

    if(arg)
    {
        if (file_size(HELP_DIR + arg) > 0)
        {
            me->more_file(HELP_DIR + arg);
            return 1;
        }
        else if( objectp(file = COMMAND_D->find_command(arg)) ) {
            // notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
            return file->help(me);
        }
    }

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%|50s| \n", MAG "*" HIY "游戏基础指令列表" NOR MAG "*" NOR);
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-10s%-40s| \n", " 基础指令", "quit save i l hp team");
    msg += sprintf(" |%-10s%-40s| \n", " 道具指令", "equip remove get give drop use");
    msg += sprintf(" |%-10s%-40s| \n", " 背包指令", "bag take store");
    msg += sprintf(" |%-10s%-40s| \n", " 战斗指令", "kill exert skills cast magic");
    msg += sprintf(" |%-10s%-40s| \n", " 聊天指令", "say chat bill shout");
    msg += sprintf(" |%-10s%-40s| \n", " 信息指令", "sc who top mudinfo skill title quest");
    msg += sprintf(" |%-10s%-40s| \n", " 特殊指令", "home suicide halt");
    msg += sprintf(" |%-10s%-40s| \n", " 管理指令", "passwd");
    msg += sprintf(" |%-10s%-40s| \n", " 帮助指令", "color help id map bbs");
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;

    write(msg);
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
