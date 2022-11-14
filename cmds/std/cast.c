#include <ansi.h>
#include <skill.h>

inherit _CLEAN_UP;

int main(object me, string arg)
{
    string spell, target;
    mixed who;

    if (me->is_busy())
        return notify_fail("( 你上一个动作还没有完成，不能施用咒文。)\n");

    if (!arg)
        return notify_fail("你要用什么咒文？\n");

    if (sscanf(arg, "%s on %s", spell, target) == 2)
    {
        if (!objectp(who = present(target, environment(me))))
        {
            return notify_fail("这里没有这个人。\n");
        }
    }
    else
    {
        spell = arg;
    }
    // 为什么不在咒文代码中判断？因为没学回也可能通过道具施法，所以只在普通施法指令中限制
    if (userp(me) && !me->query_spell(spell))
    {
        return notify_fail("你还没有学会这个咒文。\n");
    }
    if (!find_object(F_SPELL(spell)) && file_size(F_SPELL(spell) + ".c") < 0)
    {
        return notify_fail("你还没有学会这个咒文。\n");
    }

    if (me->is_fighting())
    {
        me->set_temp("combat_action", spell);
        me->set_temp("action_target", who);
        msg("magic", "$ME开始吟唱咒文" + chinese(F_SPELL(spell)->spell_name()) + "。", me);
    }
    else
    {
        return F_SPELL(spell)->do_effect(me, who);
    }

    return 1;
}

int help (object me)
{
    write(@HELP
指令格式：cast <咒文> [on <对象>]

使用魔法咒文，具体掌握的咒文可以使用 spells 指令查看。

HELP );
    return 1;
}
