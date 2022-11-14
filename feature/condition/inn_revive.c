#include <ansi.h>
#include <buff.h>

inherit _CONDITION_MOD;

nosave string id = "inn_revive";
nosave string name = NOR HIG "安逸时光" NOR;
nosave string type = "增益";
nosave int time = 3600;
nosave int heartbeat = 10;

void revive(object ob);

// 状态开始生效效果
void start_effect(object ob)
{
    tell_object(ob, HIC "你进入了" + name + HIC "的增益状态。\n" NOR);
}

// 状态失效效果
void stop_effect(object ob)
{
    tell_object(ob, YEL "你失去了" + name + YEL "的增益状态。\n" NOR);
}

// 状态持续效果
void heart_beat_effect(object ob)
{
    revive(ob);
}

void revive(object ob)
{
    int hp, max_hp;

    if (!objectp(ob))
    {
        return;
    }
    if (!environment(ob)->is_inn())
    {
        ob->change_condition_time(CD_INN_REVIVE, 0);
        return;
    }

    hp = ob->query_hp(), max_hp = ob->query_max_hp();

    if (hp < max_hp - 5)
    {
        ob->add_attr("hp", 1 + random(5));
        // tell_object(ob, HIG "安逸的呆在旅馆，你感觉自己的体力恢复了一些。\n" NOR);
    }
    if (hp > max_hp)
        ob->set_hp_full();
}
