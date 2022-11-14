#include <ansi.h>
inherit _CLEAN_UP;

int help(object me);
int finish(string questid, mapping data, int finish);

int main(object me, string arg)
{
    string msg;
    object ob;
    mapping quest, quest0, quest1;
    int num, i = 0, size = 0, size0 = 0, size1 = 0;

    return notify_fail(FCC(208)"旧任务接口已废弃，请使用指令 quest 管理任务。\n"NOR);

    // 个人任务列表
    quest = me->query_quests();
    if (mapp(quest))
    {
        size = sizeof(quest);
        // 未完成任务列表
        quest0 = filter_mapping(quest, (: finish :));
        size0 = sizeof(quest0);
        // 已完成任务列表
        quest1 = filter_mapping(quest, (: finish :), 1);
        size1 = sizeof(quest1);
    }

    if (!arg)
    {
        if (!size0)
            return notify_fail("你没有待完成的任务，请输入 " HIY "help quest" NOR " 了解更多。\n");

        msg = "你待完成的任务列表如下(总共 " + size + " 个任务，待完成 "+ size0 + " 个)：\n";

        msg += WHT "--------------------------------------------------------\n" NOR;
        foreach (string questid, mapping data in quest0)
        {
            i++;

            msg += sprintf(HIW "%-4s" NOR "%s %s\n    " HIB "说明" NOR "：%s\n" NOR,
                i + ".", data["name"] + NOR YEL " ─ " HIY + TIME_D->replace_ctime(data["time"]) + NOR,
                RED "(未完成)" NOR, data["note"] ? data["note"] : "暂无说明");
        }

        msg += WHT "--------------------------------------------------------\n" NOR;
        msg += YEL "  输入 quest id -i 查看任务详情，如：quest 1 -i\n" NOR;
        write(msg);
    }
    else if (arg == "-c")
    {
        if (!size1)
            return notify_fail("你没有已完成的任务，请输入 " HIY "help quest" NOR " 了解更多。\n");

        msg = "你已完成的任务列表如下(总共 " + size + " 个任务，已完成 "+ size1 + " 个)：\n";

        msg += WHT "--------------------------------------------------------\n" NOR;
        foreach (string questid, mapping data in quest1)
        {
            i++;

            msg += sprintf(HIW "%-4s" NOR "%s %s\n    " HIB "说明" NOR "：%s\n" NOR,
                i + ".", data["name"] + NOR YEL " ─ " HIY + TIME_D->replace_ctime(data["time"]) + NOR,
                GRN "(" HIG "已完成" + NOR GRN ")" NOR, data["note"] ? data["note"] : "暂无说明");
        }

        msg += WHT "--------------------------------------------------------\n" NOR;
        write(msg);
    }
    else if (sscanf(arg, "%d -d", num) == 1 && arg[ < 2.. < 1] == "-d")
    {
        if (num <= 0 || num > size0)
            return notify_fail("没有这个任务(只能删除未完成的任务)，请输入 quest 查看列表。\n");

        foreach (string questid, mapping data in quest0)
        {
            i++;
            if (i == num)
            {
                // if (me->query_quest_finish(questid))
                // {
                //     return notify_fail("任务「" + data["name"] + "」已经完成，无法取消。\n");
                // }

                if (!bitCheck(data["type"], 3))
                {
                    return notify_fail("任务「" + data["name"] + "」必须完成，无法取消。\n");
                }

                me->delete_quest(questid);
                me->save();

                write("刪除任务「" + data["name"] + "」完成。\n");
                return 1;
            }
        }
    }
    else if (sscanf(arg, "%d -i", num) == 1 && arg[ < 2.. < 1] == "-i")
    {
        if (num <= 0 || num > size0)
            return notify_fail("没有这个任务(只能查看未完成的任务详情)，请输入 quest 查看列表。\n");

        foreach (string questid, mapping data in quest0)
        {
            i++;
            if (i == num)
            {
                // if (me->query_quest_finish(questid))
                // {
                //     return notify_fail("任务「" + data["name"] + "」已经完成，不用再关注详细内容啦。\n");
                // }
                msg = "***任务[" + data["name"] + "]详情***\n";
                msg += "任务说明：" + data["note"] + "\n";
                msg += "任务奖励：经验 " + data["data"]["bonus"]["exp"] + "，金币 " + data["data"]["bonus"]["coin"] + "\n";
                // 称号奖励
                if (data["data"]["bonus"]["title"])
                {
                    msg += "称号奖励：" + data["data"]["bonus"]["title"] + "\n";
                }
                // 物品奖励
                if (mapp(data["data"]["bonus"]["item"]))
                {
                    msg += "物品奖励：\n";
                    foreach(string item, int n in data["data"]["bonus"]["item"])
                    {
                        msg += " - " + item->short() + " : " + n + "\n";
                    }
                }
                if (data["data"]["kill"])
                {
                    mapping cr = me->query_combat_records();
                    if (mapp(cr))
                    {
                        msg += "完成情况：\n";
                        foreach(string mob, int n in data["data"]["kill"])
                        {
                            msg += " - " + chinese(mob) + " : " + (cr["mob"][mob] - data["data"]["base_mob"][mob]) + " / " + n + "\n";
                        }
                    }
                }
                write(msg);
                return 1;
            }
        }
    }
    else if (objectp(ob = present(arg, environment(me))) && ob != me)
    {
        if (ob->is_quester())
        {
            if (size0 > 9)
            {
                return notify_fail("你未完成的任务过多，请取消或完成后再接新任务吧。\n");
            }

            if (!ob->complete_quest(me))
            {
                return ob->ask_quest(me);
            }
        }
        else
        {
            if (userp(ob))
            {
                return notify_fail("干得漂亮，你的想法很棒！\n");
            }
            else
            {
                msg("info", "$ME对$YOU说到：我这里没有任务呀，你找别人试试吧。", ob, me);
            }
            return 1;
        }
    }
    else
    {
        return help(me);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : quest            - 查询未完成任务列表
           quest -c         - 查看已完成任务
           quest [id] -d    - 取消未完成的任务，id 为未完成任务列表中的编号
           quest [id] -i    - 查看指定任务详情，id 为未完成任务列表中的编号
           quest npc        - 接受｜完成任务，如：quest monster hunter

这个指令可以让你查询自己的任务、放弃未完成的任务、接受及完成 NPC 的任务。

HELP );
    return 1;
}

int finish(string questid, mapping data, int finish)
{
    if (finish)
        return data["finish"];
    else
        return !data["finish"];
}
