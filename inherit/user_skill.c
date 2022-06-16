/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_skill.c
Description: 玩家角色特技继承接口
Author: xuefeng
Version: v1.0
Date: 2019-03-24
History:
*****************************************************************************/
mapping skills;

void set_skill(string skill, int val)
{
    if (!find_object(F_SKILL(skill)) &&
        file_size(F_SKILL(skill) + ".c") < 0)
        error("F_SKILL: No such skill (" + skill + ")\n");

    if (!mapp(skills))
        skills = ([skill:val]);
    else
        skills[skill] = val;
}

int delete_skill(string skill)
{
    if (mapp(skills))
    {
        map_delete(skills, skill);
        return undefinedp(skills[skill]);
    }
    return 0;
}

int query_skill(string skill)
{
    if (mapp(skills) && !undefinedp(skills[skill]))
        return skills[skill];
    return 0;
}

mapping query_skills() { return skills; }

// 装备被动技能效果
void skill_effect(string skill, int type)
{
    object me = this_object();
    int i, *bskill = me->query_temp("skill/" + skill);

    if (!me->query_skill(skill))
        return;
    if (!find_object(F_SKILL(skill)) && file_size(F_SKILL(skill) + ".c") < 0)
        return;
    if (F_SKILL(skill)->skill_type() != TYPE_X)
        return;

    if (!type && arrayp(bskill))
    {
        foreach(i in bskill)
        {
            me->add_temp("buff/attr/damage", -(F_SKILL(skill)->effect(i)["damage"]));
            me->add_temp("buff/attr/defense", -(F_SKILL(skill)->effect(i)["defense"]));
            me->add_temp("buff/attr/critical", -(F_SKILL(skill)->effect(i)["critical"]));
            me->add_temp("buff/attr/dodge", -(F_SKILL(skill)->effect(i)["dodge"]));
            me->add_temp("buff/attr/parry", -(F_SKILL(skill)->effect(i)["parry"]));
            me->add_temp("buff/attr/max_hp", -(F_SKILL(skill)->effect(i)["max_hp"]));
            me->add_temp("buff/attr/max_mp", -(F_SKILL(skill)->effect(i)["max_mp"]));
            me->add_temp("buff/attr/mp_rate", -(F_SKILL(skill)->effect(i)["mp_rate"]));
            me->add_temp("buff/attr/mp_regen", -(F_SKILL(skill)->effect(i)["mp_regen"]));
            me->add_temp("buff/attr/family", -(F_SKILL(skill)->effect(i)["family"]));
            me->delete_temp("skill/" + skill, ({i}));
        }
    }
    else
    {
        for(i = 1; i <= 10; i++)
        {
            if (bitCheck(me->query_skill(skill), i) && (!arrayp(bskill) || (member_array(i, bskill) < 0)))
            {
                me->add_temp("buff/attr/damage", F_SKILL(skill)->effect(i)["damage"]);
                me->add_temp("buff/attr/defense", F_SKILL(skill)->effect(i)["defense"]);
                me->add_temp("buff/attr/critical", F_SKILL(skill)->effect(i)["critical"]);
                me->add_temp("buff/attr/dodge", F_SKILL(skill)->effect(i)["dodge"]);
                me->add_temp("buff/attr/parry", F_SKILL(skill)->effect(i)["parry"]);
                me->add_temp("buff/attr/max_hp", F_SKILL(skill)->effect(i)["max_hp"]);
                me->add_temp("buff/attr/max_mp", F_SKILL(skill)->effect(i)["max_mp"]);
                me->add_temp("buff/attr/mp_rate", F_SKILL(skill)->effect(i)["mp_rate"]);
                me->add_temp("buff/attr/mp_regen", F_SKILL(skill)->effect(i)["mp_regen"]);
                me->add_temp("buff/attr/family", F_SKILL(skill)->effect(i)["family"]);
                me->add_temp("skill/" + skill, ({i}));
            }
        }
    }
}
