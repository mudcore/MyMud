#include <ansi.h>
inherit _CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    mapping vocation_info, skill_info;
    string *skills, msg;
    int sk, sp, *sk_sp, lv = 1;

    vocation_info = VOCATION_D->vocation_info(me->query("vocation"));

    if (mapp(vocation_info) && (skills = vocation_info["skill"]))
    {
        if (!sizeof(skills))
            return notify_fail(HIR "你没有任何职业技能！\n" NOR);

        if (!arg)
        {
            msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
            msg += sprintf(" |%|50s| \n", MAG "*" HIY "职业技能" NOR MAG "*" NOR);
            msg += " |--------------------------------------------------| \n" NOR;
            msg += sprintf(" |  %|16s%|32s| \n", "技能类别", "分配点数");
            foreach (string skill in skills)
            {
                msg += sprintf(" |  %|16s%|32d| \n", chinese(skill), me->query("skill/" + skill));
            }

            msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
            msg += YEL "  * 更多技能帮助请输入：help skill\n" NOR;
            tell_object(me, msg);
            return 1;
        }
        else if (sscanf(arg, "%d add %d", sk, sp) == 2)
        {
            if (sk >= 1 && sk <= sizeof(skills))
            {
                if (me->query_sp() < sp || sp < 0)
                    return notify_fail(HIR "你可分配的技能点数没有这么多呀。\n" NOR);

                if (100 - me->query("skill/" + skills[sk - 1]) < sp)
                {
                    return notify_fail(HIR "每类技能最多可分配 100 点 SP。\n" NOR);
                }

                me->add("skill/sp/sk" + sk, sp); // 记录此职业技能已分配点数
                sk = sk - 1;
                me->add("skill/" + skills[sk], sp); // 记录此技能总分配点数
                write("技能点分配完成！\n");
                SKILL_D->learn_skill(me, sk);
                return 1;
            }
            else
                return help(me);
        }
        else
        {
            sk = atoi(arg);
            if (sk >= 1 && sk <= sizeof(skills))
            {
                sk = sk - 1;
                skill_info = SKILL_D->skill(skills[sk]);
                if (mapp(skill_info) && sizeof(skill_info))
                {
                    sk_sp = keys(skill_info);
                    sk_sp = sort_array(sk_sp, 1);
                    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
                    msg += sprintf(" |%|50s| \n", MAG "*" HIY + chinese(skills[sk]) + "系职业技能" NOR MAG "*" NOR);
                    msg += " |--------------------------------------------------| \n" NOR;
                    msg += sprintf(" |%|6s %|6s%|32s     | \n", "等级", "ＳＰ", "说明");
                    foreach (int p in sk_sp)
                    {
                        if (p <= me->query("skill/" + skills[sk]))
                        {
                            msg += sprintf(" |" CYN "%|6d %4d   %-36s" NOR "| \n", lv, p, (skill_info[p][0] == skills[sk] ? skill_info[p][1] : "(技)" + chinese(skill_info[p][0])));
                        }
                        else
                            msg += sprintf(" |%|6d %4d   %-36s| \n", lv, p, (skill_info[p][0] == skills[sk] ? skill_info[p][1] : "(技)" + chinese(skill_info[p][0])));
                        lv++;
                    }
                    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
                    tell_object(me, msg);
                    return 1;
                }
                else
                    return notify_fail(HIM + chinese(skills[sk]) + "系职业技能暂未开放！\n" NOR);
            }
        }
        return help(me);
    }
    return notify_fail(HIR "你没有任何职业技能！\n" NOR);
}

int help(object me)
{
    write(@HELP
指令格式 : skill [ 1 | 2 | 3 | 4 | 5 ]

    skill - 查看个人当前职业技能类别及点数分配
    skill 1~5 - 查看指定类别技能详情
    skill 1~5 add [sp] - 分配技能点数到指定类别

相关指令：skills、spells
HELP );
    return 1;
}
