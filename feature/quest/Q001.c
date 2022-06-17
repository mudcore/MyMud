#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務
int isQuest() { return 1; }

/** 此任務是否能重複解
    return 0  不能重複
    return 1  可重複
    建議最好設定不能重複
 */
int isNewly() { return 0; }

// 任務名稱
string getName()
{
    return "旅途的开始";
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "冒险总是需要战斗的，去村口打败一只史莱姆吧。\n";

    return msg;
}

// 任務等級
int getLevel()
{
    return 1;
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
    return 1;
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "1/npc/girl.c"; // 小女孩
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "你想成为冒险者吗？去帮我打败一只史莱姆吧。" NOR,
        "$ME对$YOU說道：" HIG "虽然史莱姆看起来很可爱，但也会攻击村民的呀。" NOR,
        "$ME对$YOU說道：" HIG "从这里一路向南可以出村，出村后记得不要跑太远哦。" NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill()
{
    return ([
        MOB_DIR "9/1.c" : 1,   // 史莱姆
    ]);
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
    return WORLD_9_DIR "1/npc/girl.c"; // 小女孩
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME高興地跳了起来。" NOR,
        CYN "$ME對著$YOU說道：不要奇怪为什么第一个任务就是出村冒险，因为弱小的你有女神的护佑，哪怕死去也能复活。" NOR,
        HIG "$ME想了想又对$YOU说：对了，如果你想接受更多的任务，可以去旅店，听说旅店里有客人需要帮助。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：20\n金币：20\n";
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
    REWARD_D->bonus(player, 20, 20);
}
