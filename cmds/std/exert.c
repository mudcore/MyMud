#include <ansi.h>
#include <skill.h>

inherit _CLEAN_UP;

int main(object me, string arg)
{
    string skill, target;
    mixed who;

    if (me->is_busy())
        return notify_fail("( 你上一个动作还没有完成，不能使用技能。)\n");

    if (!arg)
        return notify_fail("你要用什么技能？\n");

    if (sscanf(arg, "%s on %s", skill, target) == 2)
    {
        if (!objectp(who = present(target, environment(me))))
        {
            return notify_fail("这里没有这个人。\n");
        }
    }
    else
    {
        skill = arg;
    }

    if (userp(me) && !me->query_skill(skill))
    {
        return notify_fail("你还没有学会这个技能。\n");
    }

    if (file_size(F_SKILL(skill) + ".c") <= 0)
    {
        return notify_fail("该技能暂未开放，敬请期待吧。\n");
    }
    if (F_SKILL(skill)->skill_type() == TYPE_X)
        return notify_fail("被动技能无需使用。\n");

    // return notify_fail("技能系统暂未开放哦。\n");
    if (arg == "x-fist" && me->query_temp("equip/weapon"))
    {
        return notify_fail("你必须空手才能使用此技能。\n");
    }
    if ((sscanf(arg, "z-%s", arg) || sscanf(arg, "x-%s", arg)))
    {
        if (me->query_temp("equip/weapon")->query("equip_info")["weapon"] != arg)
            return notify_fail("你必须装备" + chinese(arg) + "才能使用此技能。\n");
    }

    if (me->is_fighting())
    {
        me->set_temp("combat_action", skill);
        me->set_temp("action_target", who);
        msg("skill", "$ME开始使用特技" + chinese(F_SKILL(skill)->skill_name()) + "。", me);
    }
    else
    {
        return F_SKILL(skill)->do_effect(me, who);
    }

    return 1;
}

int help (object me)
{
    write(@HELP
指令格式：exert <技能> [on <对象>]

使用职业技能，具体掌握的特技可以使用 skills 指令查看。

HELP );
    return 1;
}
