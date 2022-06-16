/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: damage.c
Description: 伤害控制接口，配合战斗系统使用，由标准角色对象继承
Author: xuefeng
Version: v1.0
Date: 2019-05-01
History:
*****************************************************************************/
#include <attribute.h>
#include <dbase.h>

nosave string *dead_msg = ({
    "$ME慢慢倒在地上，身体化为一道流光消失了。",
    "$ME无力的挣扎几下后，化做泡影消失在大家眼前。",
});

nosave object last_damage_from = 0;

object query_last_damage_from()
{
    return last_damage_from;
}

// damage 为负时为恢复
varargs int receive_damage(string type, int damage, object who)
{
    int val, max;

    if (type != "hp" && type != "mp")
        error("receive_damage: 伤害种类错误(只能是 hp 或 mp)。\n");

    if (damage == 0)
        return 0;

    if (damage > 0 && objectp(who) && who != last_damage_from)
    {
        last_damage_from = who;
    }

    val = (int)query_attr(type) - damage;
    max = (type == "hp") ? query_max_hp() : query_max_mp();

    if (val >= max) // 恢复不超过最大值
        set_attr(type, max);
    else
        set_attr(type, val);

    return damage;
}

varargs void die(object killer)
{
    object me;
    string rebornroom;
    me = this_object();

    if (!killer)
    {
        killer = last_damage_from;
    }

    msg("vision", element_of(dead_msg), me);

    REWARD_D->killer_reward(killer, me);

    if (userp(me))
    {
        // 清除临时状态
        me->delete_temp("status");
        // 清除增益状态
        me->clean_condition();
        // todo 新增虚弱效果

        if (!stringp(rebornroom = me->query("reborn_room")) ||
            file_size(rebornroom + ".c") < 0)
            rebornroom = START_ROOM;
        me->move(rebornroom);
        me->start_busy(3);
        me->save();
    }
    else
    {
        set_heart_beat(0);
        destruct(me);
    }
}
