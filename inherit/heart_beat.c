/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: heart_beat.c
Description: 所有角色心跳控制（行为/状态）接口 HEART_BEAT
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit _ACTION;
inherit _ATTACK;
inherit _ATTRIBUTE;
inherit _CONDITION;
inherit _DAMAGE;
inherit _DBASE;
inherit _MOVE;

// todo 增加指令频率限制
private nomask void process_command_decay() {}

// 临时状态变化
private nomask void process_temp_status()
{
    mapping status = query_temp("status");

    if (!mapp(status) || !sizeof(status))
        return;

    foreach (string key, int time in status)
    {
        if (time == -1)
            continue;

        if (--time <= 0)
            map_delete(status, key);
        else
            status[key] = time;
    }

    if (!sizeof(status))
        delete_temp("status");
    else
        set_temp("status", status);
}

// 非临时状态变化
private nomask void process_condition()
{
    mapping condition;

    if (mapp(condition = query("condition")))
    {
        foreach (string key, mapping value in condition)
        {
            if (value["time"] <= 0)
            {
                catch(replace_string(key, "#", "/")->stop_effect(this_object()));
                delete("condition/" + key);
                // 避免状态超过上限
                if (is_hp_full())
                {
                    set_hp_full();
                }
                if (is_mp_full())
                {
                    set_mp_full();
                }

                continue;
            }

            if (value["heart_beat"] > 0 && !(value["time"] % value["heart_beat"]))
                catch(replace_string(key, "#", "/")->heart_beat_effect(this_object()));

            add("condition/" + key + "/time", -1);
        }
    }
}

void heart_beat()
{
    mapping my = query_entire_dbase();
    object me = this_object();

    process_temp_status();
    process_condition();

    // 死亡相关控制
    if (my["attr"]["hp"] <= 0)
    {
        // todo 组队死亡后不自动复活回城

        // 调用在 DAMAGE 中定义的死亡处理函数
        die();
    }
    // 行动相关控制
    if (objectp(me) && clonep(me) && living(me))
    {
        // 处理busy
        if (is_busy())
        {
            continue_action();
        }
        else if (interactive(me))
        {
            if (is_fighting())
            {
                // 战斗吧，皮卡丘
                attack();
            }
            else if (query_temp("combat_status"))
            {
                delete_temp("combat_status");
                delete_temp("combat_round");
                delete_temp("combat_action");
                delete_temp("action_target");
            }
        }
        else if (!userp(me))
        {
            // ＮＰＣ行为(包括战斗和非战斗状态)
            me->action();
        }
    }
    // 存档和公告
    if (objectp(me) && userp(me))
    {
        int period;
        period = time() - ((int)my["last_saved_at"]);
        if (period < 0 || period > 5 * 60)
        {
            // 玩家定期存档
            command("save silence");
            // 随机公告
            if (!random(10))
            {
                string *notice = read_lines(NOTICE);
                if (sizeof(notice))
                {
                    message(element_of(({"warning", "danger", "success"})), element_of(notice), me);
                }
            }
        }
    }
}
