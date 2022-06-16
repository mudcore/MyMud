/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: reward_d.c
Description:奖励系统守护进程 REWARD_D
Author: xuefeng
Version: v1.1
Date: 2020-01-18
*****************************************************************************/
// 经验/金钱奖励
varargs void bonus(object me, int exp, int coin)
{
    string msg;

    if (coin)
    {
        me->add("coin", coin);
        if (coin > 0)
        {
            msg = "$ME获得了" + coin + "枚金币。";
            msg("warning", msg, me);
        }
        if (coin < 0)
        {
            msg = "$ME损失了" + abs(coin) + "枚金币。";
            msg("danger", msg, me);
        }
    }
    if (exp)
    {
        me->add("exp", exp);
        if (exp > 0)
        {
            msg = "你获得了" + exp + "点经验。\n";
        }
        if (exp < 0)
        {
            msg = "你损失了" + abs(exp) + "点经验。\n";
        }
        tell_object(me, msg);
        LEVEL_D->level_up(me); // 升级
        SPELL_D->learn_spell(me);
    }
}

// 战斗胜利奖励
void killer_reward(object killer, object victim)
{
    mapping ks, vs;
    string msg;
    object * drop_item, item;
    int coin, exp;

    vs = victim->query_entire_dbase();

    // 受害玩家死亡损失
    if (userp(victim)) {
        victim->add_combat_record("die", 1);
        if (victim->query("coin") > 999) {
            coin = -random(victim->query("coin") / 100);
        }
        if (victim->query("lv") > 9) {
            exp = -random(victim->query("exp") / 100);
        }
        bonus(victim, exp, coin);
        victim->set_attr("hp", victim->query_max_hp()); // 恢复HP到当前等级最大值
    }

    // 死亡奖励是由受害者触发，如果胜利者是ＮＰＣ有可能正好被其他玩家杀掉。
    if (objectp(killer))
    {
        ks = killer->query_entire_dbase();
        if (userp(killer))
        {
            // debug_message("victor: " + killer);
            if (!userp(victim))
            {
                // 默认经验金钱倍率
                exp = vs["exp"] / 2;
                coin = vs["coin"] / 2;
                // 越级杀怪经验减少
                if (vs["exp"])
                {
                    if (random(killer->query_score(1)) > victim->query_score() * 3)
                    {
                        exp = 1;
                    }
                    if (killer->query("lv") >= LEVEL_D->max_level())
                    {
                        exp = 0;
                    }
                }
                // 1/4的几率获得金币
                if (random(4)) {
                    coin = 0;
                }
                // 获得掉落物品
                if (mapp(vs["drop_item"]) && sizeof(vs["drop_item"])) {
                    drop_item = keys(vs["drop_item"]);
                    foreach(item in drop_item){
                        if (!random(vs["drop_item"][item])) {
                            item = new(item);
                            item->move(killer);
                            msg = "怪物掉落了宝箱，$ME打开宝箱获得了" + item->name() + "。";
                            msg("success", msg, killer);
                        }
                    }
                }
                killer->add_combat_record("kill", 1);
                killer->add_mob_record(victim->query("id"), 1);
                // 任务记录
                QUEST_D->doKilled(victim, killer);
                // 如果是迷宫，随机获得地图
                if (environment(killer)->query("maze_room"))
                {
                    int *maze_room = killer->query_temp("maze") || ({});
                    int area = environment(killer)->query("area");
                    if (member_array(area, maze_room) < 0 && !random(10))
                    {
                        // 获取迷宫地图
                        sizeof(maze_room) ? killer->add_temp("maze", ({area})) : killer->set_temp("maze", ({area}));
                        tell_object(killer, "\033[48;5;208m你获得了迷宫地图，现在可以在这里使用map here导航啦。\033[0m\n");
                    }
                }
                // 组队奖励
                if (sizeof(killer->query_team()) > 1)
                {
                    // 不管多少人组队，每个人获得 1/2 收益
                    exp = to_int(round(exp / 2.0));
                    coin = to_int(round(coin / 2.0));
                    foreach(object me in killer->query_team())
                    {
                        // 必须在同一个地区，防止远程挂机
                        if (environment(me) == environment(killer))
                            bonus(me, exp, coin);
                    }
                }
                else
                    bonus(killer, exp, coin);
            } else
                killer->add_combat_record("pk", 1);
        }
    }
}
