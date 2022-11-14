#include <ansi.h>
#include <buff.h>

inherit _CONDITION_MOD;

nosave string id = "blessing";
nosave string name = NOR HIY "女神的祝福" NOR;
nosave string type = "增益";
nosave int time = 36000;
nosave int heartbeat = 100;

// 状态开始生效效果
void start_effect(object ob)
{
    ::start_effect(ob);
    ob->add(BUFF_MAX_HP, 25);
    ob->add(BUFF_MAX_MP, 15);
    ob->add(BUFF_STR, 15);
    ob->add(BUFF_VIT, 15);
    ob->add(BUFF_INT, 15);
    ob->add(BUFF_MEND, 15);
}

// 状态失效效果
void stop_effect(object ob)
{
    ::stop_effect(ob);
    ob->add(BUFF_MAX_HP, -25);
    ob->add(BUFF_MAX_MP, -15);
    ob->add(BUFF_STR, -15);
    ob->add(BUFF_VIT, -15);
    ob->add(BUFF_INT, -15);
    ob->add(BUFF_MEND, -15);
}

// 状态持续效果
void heart_beat_effect(object ob)
{
}
