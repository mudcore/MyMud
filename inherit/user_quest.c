/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_quest.c
Description: 玩家任务功能接口 USER_QUEST
Author: xuefeng
Version: v1.0
Date: 2019-05-05
*****************************************************************************/
inherit CORE_USER_QUEST;

// 自定义任务接口
#include <ansi.h>
#include <treemap.h>
// 任务存档
mapping quests;

// 获取所有 quest
mapping query_quests() { return quests; }

// 设定 quest 记录
varargs void set_quest_note(string quest, string name, string note, int type)
{
    if (!mapp(quests))
        quests = ([]);

    _set(quests, ({quest, "time"}), time()); // 任务接受或更新时间
    _set(quests, ({quest, "name"}), name);   // 任务名称
    _set(quests, ({quest, "note"}), note);   // 任务描述
    _set(quests, ({quest, "type"}), type);   // 任务类型
    _set(quests, ({quest, "finish"}), 0);    // 任务完成状态

    tell_object(this_object(), HIY "任务信息更新，请使用 quest 指令查看。\n" NOR);
}

// 设定 quest data
void set_quest_data(string quest, mixed value)
{
    _set(quests, ({quest, "data"}), value);
}

// 新增 quest data
void add_quest_data(string quest, string key, mixed value)
{
    _set(quests, ({quest, "data", key}), value);
}

// 取得 quest 资料
mixed query_quest(string quest)
{
    return _query(quests, ({quest}));
}

// 取得 quest data
varargs mixed query_quest_data(string quest, string key)
{
    if (key)
    {
        return _query(quests, ({quest, "data", key}));
    }
    return _query(quests, ({quest, "data"}));
}

// 刪除 quest
void delete_quest(string quest)
{
    _delete(quests, ({quest}));
}

// 清除所有 quest
void delete_quests()
{
    quests = ([]);
}

// 设定 quest 步骤
void set_quest_step(string quest, int step)
{
    _set(quests, ({quest, "step"}), step);
}

// 取得 quest 步骤
int query_quest_step(string quest)
{
    return _query(quests, ({quest, "step"}));
}

// 设定此 quest 已经结束
void set_quest_finish(string quest)
{
    _set(quests, ({quest, "finish"}), 1);
    _delete(quests, ({quest, "step"}));
    _delete(quests, ({quest, "data"}));
}

// 检查 quest 是否已经结束
int query_quest_finish(string quest)
{
    return _query(quests, ({quest, "finish"})) || isSolved(F_QUEST(quest));
}

// 取得 quest 接受时间
int query_quest_time(string quest)
{
    return _query(quests, ({quest, "time"}));
}
