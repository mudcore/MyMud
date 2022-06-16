#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務
int isQuest() { return 1; }

/** 此任務是否能重複解
    return 0  不能重複
    return 1  可重複
    建議最好設定不能重複
 */
int isNewly() { return 1; }
// 此任务可否放弃
int noGiveUp() { return 1; }

// 任務名稱
string getName()
{
    return HIR"怪物猎人－中级"NOR;
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "击杀指定数量的魔物，获得怪物猎人的奖赏。\n";

    return msg;
}

// 任務等級
int getLevel()
{
    return 15;
}

/* 接受任務的前置條件，可能是
        1. 等級需求
        2. 職業需求
        3. 種族需求
        4. 已完成某些任務需求
    等等，應可以自由發揮才是。
    回傳非零值表示符合條件。
 */
int preCondition(object player)
{
    return player->query("lv") >= getLevel() && !player->query_quest_data("hunter");
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "npc/hunter.c"; // 怪物猎人
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "想成为勇士吗？来我这里接受挑战吧。" NOR,
        "$ME对$YOU說道：" HIG "击杀当前地区的一定数量的特定魔物，我可以给你丰富报酬。" NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill()
{
    object me = this_interactive();
    // 记录随机任务数据
    if (!me->query_quest_data("hunter"))
    {
        int area = environment(me)->query("area");
        int id = element_of(AREA_D->mob_list(area, 2));
        int num = element_of(({35, 40, 45, 50, 55, 60}));
        mapping mobs = ([ MOB_DIR "9/" + id + ".c" : num]);
        me->set_quest_data("hunter", mobs);
    }

    return me->query_quest_data("hunter") || ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
mapping getItem()
{
    return ([]);
}

// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    return 1;
}

// 完成任務的NPC (以檔名來識別)
string getRewarder()
{
    return WORLD_9_DIR "npc/hunter.c"; // 怪物猎人
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME對著$YOU說道：干的不错，如果有兴趣的话，你还可以继续接受这个挑战哦。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg;
    int exp = 0, coin = 0;
    mapping data = this_interactive()->query_quest_data("hunter") || ([]);
    foreach(string mob, int num in data)
    {
        exp += mob->query("exp") * num * 9;
        coin += mob->query("coin") * num * 3;
    }
    msg = "经验：" + (exp||"???") + "\n金币：" + (coin||"???") + "\n";
    return msg;
}

/** 任務獎勵
    獎勵應該能自由發揮，如：
        1. 獲得經驗
        2. 獲得物品
        3. 獲得短暫Buff
        4. 習得某技能
        5. 更改玩家狀態, ex: 轉職
 */
void reward(object player, object npc)
{
    int exp = 0, coin = 0;
    mapping data = player->query_quest_data("hunter");
    foreach(string mob, int num in data)
    {
        exp += mob->query("exp") * num * 9;
        coin += mob->query("coin") * num * 3;
    }
    REWARD_D->bonus(player, exp, coin);
    // 清除临时记录
    player->delete_quest("hunter");
}
