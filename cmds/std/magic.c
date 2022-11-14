#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    string msg;
    mapping spells = me->query_spells();
    if(!sizeof(spells))
        return notify_fail(HIB "你还不会任何魔法咒文！\n" NOR);

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%|50s| \n", MAG "*" HIY "魔法书" NOR MAG "*" NOR);
    msg += " |--------------------------------------------------| \n" NOR;

    foreach(string spell in keys(spells))
    {
        msg += sprintf(" |  %-16s%-32s| \n", chinese(spell) , "吟唱咒语：cast " + spell);
    }

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    tell_object(me, msg);
    return 1;
}

int help (object me)
{
    write(@HELP
指令格式：magic [spell] | spells

查看魔法书记录的已学咒文。

相关指令：skills
HELP );
    return 1;
}
