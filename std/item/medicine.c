/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: medicine.c
Description: 游戏恢复道具标准继承对象 STD_MEDICINE
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_ITEM;

void create()
{
    ::create();
    set_name(HIG "草药" NOR, ({"medicinal herb", "medicine", "herb", "1"}));
    set("long", "我方单体HP30多恢复。");
    set("base_value", 5);
    set("value", 8);
    set("unit", "株");
    set("effect", ([
        "heal":({"hp", 30, 10}), // 恢复：类型，基础值，波动值
        "status":({}),           // 临时状态：类型（status.h），持续时间
        "buff":({}),             // 增益状态：名称（condition.h），持续时间
        "cure":({}),             // 治疗,可治疗的负面状态，包括死亡、中毒等
    ]));
}

// todo 治疗负面状态，包括死亡、中毒等
int do_effect(object me)
{
    mapping effect = query("effect");
    string type, name = query("name"), msg;

    if (mapp(effect))
    {
        if (arrayp(effect["heal"]) && sizeof(effect["heal"]) == 3)
        {
            int heal;
            type = effect["heal"][0];
            heal = effect["heal"][1] + random(effect["heal"][2]);
            if (type == "hp")
            {
                if (me->is_hp_full())
                {
                    write("你现在的状态无需使用" + name + "。\n");
                    return 1;
                }
                msg = HIG "$ME使用了" + name + HIG "!$ME的伤势被治疗了。" NOR;
            }

            if (type == "mp")
            {
                if (me->is_mp_full())
                {
                    write("你现在的状态无需使用" + name + "。\n");
                    return 1;
                }
                msg = HIB "$ME使用了" + name + HIB "!$ME的魔力恢复了。" NOR;
            }

            me->receive_damage(type, -heal);
        }
        if (arrayp(effect["buff"]) && sizeof(effect["buff"]) == 2)
        {
            me->start_condition(effect["buff"][0], effect["buff"][1]);
            msg = "$ME使用了" + name + "。";
        }
        if (arrayp(effect["status"]) && sizeof(effect["status"]) == 2)
        {
            me->set_temp(effect["status"][0], effect["status"][1]);
            msg = "$ME使用了" + name + "。";
        }
        if(arrayp(effect["cure"]))
        {
            foreach(string cd in effect["cure"])
            {
                if (cd == "poison")
                    me->stop_condition(CD_POISON);
                // 死亡也是一种状态
                if (cd == "die")
                {
                    continue;// todo
                }
            }
        }
    }

    me->start_busy(2);
    msg("default", msg, me);
    add_amount(-1);
    return 1;
}
