#include <ansi.h>

string score(object me)
{
    string msg, title;
    mapping my;

    my = me->query_entire_dbase();

    if (!(title = my["title"]))
        title = "平民";

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%-50s| \n", "【" + title + "】" + me->short());
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-34s%-16s| \n", " 生日:" + ctime(my["birthday"]), "性别：" + my["gender"]);
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-27s%-23s| \n", "生命：" + me->query_hp() + " / " + me->query_max_hp(), "灵力：" + me->query_mp() + " / " + me->query_max_mp());
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "力量：" + me->query_str(), "敏捷：" + me->query_agi(), "耐力：" + me->query_vit());
    msg += sprintf(" |%-15s%-15s%-20s| \n", "智力：" + me->query_int(), "灵巧：" + me->query_dex(), "幸运：" + me->query_luk());
    msg += sprintf(" |%-15s%-15s%-20s| \n", "魔法攻击：" + me->query_m_attack(), "魔法防御：" + me->query_m_defense(), "回复力：" + me->query_mend());
    msg += sprintf(" |%-15s%-15s%-20s| \n", "攻击：" + me->query_attack(), "防御：" + me->query_defense(), "");
    msg += sprintf(" |%-50s| \n", "");
    msg += sprintf(" |%-15s%-15s%-20s| \n", "等级：" + my["lv"], "经验：" + my["exp"], "");
    msg += sprintf(" |%-50s| \n", "");
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    return msg;
}

string score_hp(object me)
{
    string msg, hpbar, mpbar;

    hpbar = GRAPH_D->draw(me->query_hp(),me->query_max_hp(), 2, 1, 10);
    mpbar = GRAPH_D->draw(me->query_mp(),me->query_max_mp(), 4, 7, 10);
    msg = sprintf(HIG "生命：%s\t灵力：%s\n" NOR, hpbar, mpbar);

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
指令格式 : score

这个指令可以让你查看个人档案资料。

HELP );
    return 1;
}
