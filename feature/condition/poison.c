#include <ansi.h>

inherit _CONDITION_MOD;

nosave string id = "posion";
nosave string name = NOR RED "中毒" NOR;
nosave string type = "伤害";
nosave int time = 60;
nosave int heartbeat = 5;

// 状态开始生效效果
void start_effect(object ob)
{
    msg("vision", "$ME受到「" + name + MAG "」的" + type + "影响。", ob);
}

// 状态失效效果
void stop_effect(object ob)
{
    msg("info", "$ME受到的「" + name + HIC "」的" + type + "效果消失了。", ob);
}

// 状态持续效果
void heart_beat_effect(object ob)
{
    ob->receive_damage("hp", 1 + random(5));
    msg("danger", "$ME受到「" + name + HIR "」的" + type + "影响。", ob);
}
