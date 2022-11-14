/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: quester.c
Description: 标准任务发布者，注意此文件已弃用，任务由守护进程统一管理
Author: xuefeng
Version: v1.0
Date: 2020-02-16
*****************************************************************************/
#include <ansi.h>
inherit STD_NPC;
inherit _QUESTER;

protected varargs void create(string vocation, int lvl)
{
    if (!stringp(vocation))
    {
        vocation = "ranger";
    }
    if (!lvl)
    {
        lvl = 30;
    }
    npc::create(vocation, lvl);
    set_name("怪物猎人", ({"monster hunter", "hunter"}));
    set("long", HIC "一个专门猎杀各种魔物的猎人，他也发布各种赏金任务。" NOR);
    set("gender", "男性");
}

// 发布任务信息
varargs mapping quest_info(int q)
{
    mapping quest_info = ([
        "id" : "hunter",        // 任务ID，唯一标识
        "name" : "怪物猎人",     // 任务名称
        "type" : 2,             // 任务类型，位域标识，具体见docs/quest.md
    ]);

    if (q)
    {
        quest_info += ([
            "note": "消灭指定数量的魔物",   // 任务说明
            "data":([                     // 任务数据
                "need" : ([               // 前提条件
                    "level" : 5,
                    "quest" : "NO1",
                    ]),
                "kill" : (["slime" : 100]),         // 灭杀任务
                "item" : (["medicinal herb" : 10]), // 物品任务
                "vocation" : "minstrel",            // 转职任务
                "bonus" : ([                // 任务奖励
                    "exp" : 1000,
                    "coin" : 200,
                    "item" : ([]),          // 物品奖励
                    "title" : "小小勇者",    // 称号奖励
                ]),
                "start_info" : ({
                    "你想成为勇者吗？去帮我打败100只史莱姆吧。",
                    "为了避免迷路，你可以使用地图(map)了解方位。"
                    }),
                "finish_info" : ({
                    "不要奇怪为什么我要消灭魔物，勇者就需要保护这个世界。",
                    "对了，如果你想接受更多的任务，可以去旅店，听说旅店里有客人需要帮助。"
                    }),
            ])
        ]);
    }

    return quest_info;
}

void init()
{
    object ob;
    if (interactive(ob = this_player()))
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if (!mapp(ob->query_quests()) || !ob->query_quest_time(quest_info()["id"]))
    {
        msg("info", "$YOU对$ME说到：“你好，冒险者，我这里有任务(quest)可能需要你的帮助。”", ob, this_object());
    }
}
