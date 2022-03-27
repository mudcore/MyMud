#include <ansi.h>

int top_list(string ob1, string ob2)
{
    int score1, score2;
    mapping my = this_player()->query_combat_record("mob");

    score1 = my[ob1];
    score2 = my[ob2];

    return score2 - score1;
}

string score(object me)
{
    string msg;
    mapping my;

    my = me->query_entire_dbase();

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%-34s%-16s| \n", "【" + (my["title"] || "---") + "】" + me->short(),
                   "职业：" + chinese(my["vocation"]));
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-34s%-16s| \n", " 生日:" + ctime(my["birthday"]), "性别：" + my["gender"]);
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-17s%-17s%-16s| \n", "ＨＰ：" + me->query_hp() + " / " + me->query_max_hp(), "ＭＰ：" + me->query_mp() + " / " + me->query_max_mp(), "ＳＰ：" + me->query_sp() + " / " + me->query_max_sp());
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "力量：" + me->query_str(), "速度：" + me->query_agi(), "耐力：" + me->query_vit());
    msg += sprintf(" |%-15s%-15s%-20s| \n", "幸运：" + me->query_luk(), "魅力：" + me->query_charm(), "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "回复魔力：" + me->query_mend(), "攻击魔力：" + me->query_magic(), "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "攻击：" + me->query_attack(), "防御：" + me->query_defense(), "");
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "等级：" + my["lv"], "经验：" + my["exp"], "金币：" + my["coin"]);
    msg += sprintf(" |%-50s| \n", "");

    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += YEL "  提示：使用 score -s 查看个人状态。\n" NOR;
    return msg;
}

string score_hp(object me)
{
    string msg, hpbar, mpbar, status = "";
    mapping condition;
    object *team;

    // 组队状态
    if (sizeof(team = me->query_team()) > 1)
    {
        msg = "*队伍成员状态*\n";
        foreach(object member in team)
        {
            hpbar = graph_draw(member->query_hp(),member->query_max_hp(), 2, 1, 10);
            mpbar = graph_draw(member->query_mp(),member->query_max_mp(), 4, 7, 10);
            msg += sprintf(HIM "%-20s" HIG "HP：%-15s\t" HIB "MP：%s\n" NOR,member->short(), hpbar, mpbar);
        }
    }
    else
    {
        if (mapp(condition = me->query("condition")))
        {
            foreach (string key, mapping value in condition)
            {
                status += replace_string(key, "#", "/")->query_condition_name() + "  ";
            }
        }

        hpbar = graph_draw(me->query_hp(),me->query_max_hp(), 2, 1, 10);
        mpbar = graph_draw(me->query_mp(),me->query_max_mp(), 4, 7, 10);
        msg = sprintf(HIG "HP：%s\t" HIB "MP：%s" NOR, hpbar, mpbar);
        msg += "\n------------------------------------------------------\n";
        msg += sprintf("状态：%s\n", status);
    }

    return msg;
}

int main(object me, string arg)
{
    string msg;

    switch (arg)
    {
    case "-s":
        msg = score_hp(me);
        break;

    default:
        msg = score(me);
    }
    write(msg);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : score [-s]

这个指令可以让你查看个人档案资料。

HELP );
    return 1;
}
