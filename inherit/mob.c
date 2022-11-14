/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: mob.c
Description: 魔物角色公共接口 MOB
Author: xuefeng
Version: v1.0
Date: 2019-03-14
History:
*****************************************************************************/
#include <status.h>

inherit _NPC;

int is_mob() { return 1; }

/**
 * 魔物主动攻击设置
 */
void init()
{
    object ob = this_player();
    object *team = ob->query_team();

    if (interactive(ob) && !ob->query_temp(STA_INVISIBLE) && !this_object()->is_fighting())
    {
        if (!arrayp(team))
        {
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob);
        }
        else
        {
            remove_call_out("kill_ob_team");
            call_out("kill_ob_team", 1, ob);
        }
    }
}
