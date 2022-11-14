#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    string msg, *list = ({ "axe", "boomerang", "bow", "claw", "fan", "hammer", "knife", "spear", "staff", "sword", "wand", "whip", "fist", "shield" });
    mapping skills = me->query_skills();
    if(!sizeof(skills))
        return notify_fail(HIY "你还没有掌握任何特技！\n" NOR);

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%|50s| \n", MAG "*" HIY "技能书" NOR MAG "*" NOR);
    msg += " |--------------------------------------------------| \n" NOR;

    foreach(string skill, int lv in skills)
    {
        if (member_array(skill, list) < 0)
            msg += sprintf(" |  %-16s%-32s| \n", chinese(skill), "特技：exert " + skill);
        else if(bitCheck(lv, 10))
            msg += sprintf(" |  %-16s%-32s| \n", "精通-" + chinese(skill), "被动技能，无需使用。 ");
        else if(lv > 16)
            msg += sprintf(" |  %-16s%-32s| \n", "熟练-" + chinese(skill), "被动技能，无需使用。 ");
        else
            msg += sprintf(" |  %-16s%-32s| \n", "掌握-" + chinese(skill), "被动技能，无需使用。 ");
    }

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    tell_object(me, msg);
    return 1;
}

int help (object me)
{
    write(@HELP
指令格式：skills

查看自己已经掌握的职业特技。

相关指令：skill
HELP );
    return 1;
}
