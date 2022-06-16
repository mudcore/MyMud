/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: team.c
Description: 游戏组队指令
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>

int main(object me, string arg)
{
    object ob, *team = me->query_team(), *tm;
    string msg, id;
    int i;

    if (me->is_busy()) {
        return notify_fail("你现在正忙着呢。\n");
    }

    if (me->is_fighting()) {
        me->start_busy(1);
        return notify_fail("你正在战斗中，先专心把敌人解决了吧。\n");
    }

    msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    msg += sprintf(" |%|50s| \n", "系统组队指令说明");
    msg += " |--------------------------------------------------| \n" NOR;
    msg += sprintf(" |%-20s%-30s| \n", "  邀请组队", "team with id");
    msg += sprintf(" |%-20s%-30s| \n", "  脱离队伍", "team leave [id]");
    msg += sprintf(" |%-20s%-30s| \n", "  队伍成员列表", "team list");
    msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;

    if (!arg) {
        return notify_fail(msg);
    }
    if (sscanf(arg, "%s %s", arg, id))
    {
        if (arg == "with")
        {
            if (!id || ! (ob = present(id, environment(me))) ||
                ! userp(ob) || ob == me)
                return notify_fail("你只能邀请身边的玩家组队。\n");

            if (me->is_team_leader())
            {
                if (sizeof(team) >= 4)
                    return notify_fail("你的队伍人数已经满了。\n");

                if (me == ob->query_temp("pending/team"))
                {
                    me->add_team_member(ob);
                    msg("info", "$ME决定让$YOU加入队伍。", me, ob);
                    ob->delete_temp("pending/team");
                    return 1;
                } else
                if (arrayp(tm = ob->query_team())) {
                    return notify_fail(ob->name() + "已经和" +
                    (tm[0] == me ? "你" : (ob->is_team_leader() ? "别人" : tm[0]->name())) +
                     "组队了。\n");
                } else
                {
                    msg("team", "$ME邀请$YOU加入$ME的队伍。", me, ob);
                    tell_object(ob, YEL "如果你愿意加入，请用 team with " +
                                me->query("id") + "。\n" NOR);
                    me->set_temp("pending/team", ob);
                    return 1;
                }
            } else
            if (! arrayp(team))
            {
                if (me == ob->query_temp("pending/team"))
                {
                    ob->add_team_member(me);
                    msg("info", "$ME加入了$YOU的队伍。", me, ob);
                    ob->delete_temp("pending/team");
                    return 1;
                } else
                if (arrayp(tm = ob->query_team()))
                {
                    if (sizeof(tm) >= 4)
                        return notify_fail(ob->name() + "的队伍人数已经满了。\n");
                    if (!ob->is_team_leader())
                    {
                        return notify_fail(ob->name() + "已经加入" +
                            tm[0]->name() + "的队伍了。\n");
                    } else
                    {
                        msg("team", "$ME申请加入$YOU的队伍。", me, ob);
                        tell_object(ob, YEL "如果你允许，请用 team with " +
                                    me->query("id") + "。\n" NOR);
                        me->set_temp("pending/team", ob);
                        return 1;
                    }
                } else {
                    msg("team", "$ME邀请$YOU加入$ME的队伍。", me, ob);
                    tell_object(ob, YEL "如果你愿意加入，请用 team with " +
                                me->query("id") + "。\n" NOR);
                    me->set_temp("pending/team", ob);
                    return 1;
                }
            } else
                return notify_fail("只有队长可以邀请别人加入。\n");
        } else
        if (arg == "leave")
        {
            if (!arrayp(team))
            {
                return notify_fail("你还没有加入任何队伍呢。\n");
            } else
            if (me->is_team_leader())
            {
                if (id == me->query("id")) {
                    me->dismiss_team();
                    msg("warning", "$ME解散了队伍。", me);
                    return 1;
                } else
                if ((ob = present(id, environment(me))) &&
                    member_array(ob, team) > 0)
                {
                    msg("warning", "$ME把$YOU移出了队伍。", me, ob);
                    ob->dismiss_team();
                    return 1;
                } else
                    return notify_fail("这个人不是你的队伍成员或者不在当前地区。\n");
            } else
            if (id == me->query("id")) {
                me->dismiss_team();
                msg("warning", "$ME退出了队伍。", me);
                return 1;
            } else
                return notify_fail("只有队长可以移出队伍成员。\n");
        }
        return notify_fail(msg);
    } else
    if (arg == "leave") {
        return notify_fail("为了防止误操作，退出队伍必须指定id。\n");
    } else
    if (arg == "list")
    {
        if (!sizeof(team))
        {
            return notify_fail("你还没有加入任何队伍呢。\n");
        }
        msg = HIC "\n≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
        msg += sprintf(" |%|50s| \n", "你的队伍成员如下");
        msg += " |--------------------------------------------------| \n" NOR;
        msg += sprintf(" |%|25s%|25s| \n", "玩家", "称号");
        msg += sprintf(" |%-25s%-25s| \n", "", "");
        for (i = 0; i < sizeof(team); i++) {
            msg += sprintf(" |%|25s%|25s| \n", team[i]->short(), team[i]->query("title"));
        }
        msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
        return notify_fail(msg);
    } else
    return notify_fail(msg);
}

int help(object me)
{
    write(@HELP
指令格式 : team with [sb] | team

这个指令可以让你和其他玩家组队。

HELP );
    return 1;
}
