/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user.c
Description: 玩家角色公共接口
Author: xuefeng
Version: v1.0
Date: 2019-03-18
History:
*****************************************************************************/
#include <ansi.h>

inherit _LIVING;
inherit _MESSAGE;
inherit _SAVE;
// 以下数据均会存档
inherit _USER_COMBAT_RECORD;
inherit _USER_DEPOT;
inherit _USER_INVENTORY;
inherit _USER_QUEST;
inherit _USER_GMCP;
inherit _USER_SKILL;
inherit _USER_SPELL;
inherit _USER_TITLE;
inherit _USER_VOCATION;

// 判断是否 user 对象，和 efun userp() 稍有区别
int is_user() { return 1; }

void setup()
{
    ::setup();
    restore_inventory();    // 取回个人物品
    restore_depot();        // 取回背包物品
    add_action("list_bag", "bag");
    add_action("do_store", "store");
    add_action("do_take", "take");
    // 激发空手被动技能
    skill_effect("fist", 1);
    // todo >>>？
    if (!mapp(toDoList))
        toDoList = ([]);
    if (!mapp(quests))
        quests = ([]);
    if (!arrayp(solved))
        solved = ({});
}

// 从游戏中移除这个玩家
void remove()
{
    // 玩家数据存档
    command("save");
    destruct(this_object());
}

// 玩家数据存档
int save()
{
    object me = this_object();
    object env = environment(me);

    if (!me) return 1;
    // 保存下线地点
    // todo 如果后期增加副本，这里需调用
    if (env && me->query("lv") > 9)
    {
        me->set("start_room", base_name(env));
    }
    // 最后存档时间
    me->set("last_saved_at", time());
    // 保存物品数据
    me->save_inventory();
    // 保存背包数据
    me->save_depot();
    // 缓存到数据库
    if (env("CACHE_DATA"))
    {
        CACHE_D->update(me);
    }

    return ::save();
}
