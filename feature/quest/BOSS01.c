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
    return "勇气的试炼";
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "击败布鲁德加，证明你的勇气。\n";
    msg += "布鲁德加在基萨格纳遗迹深处，找到它并击败它。\n";

    return msg;
}

// 任務等級
int getLevel()
{
    return 10;
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
    return player->query("lv") >= getLevel();
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "1/npc/guard.c"; // 守卫
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "你想去冒险拯救世界？先证明自己的勇气吧。" NOR,
        "$ME对$YOU說道：" HIG "你的任务是到基萨格纳遗迹中找到试炼之间，击败布鲁德加。" NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill()
{
    return ([
        MOB_DIR "9/257.c" : 1, // 布鲁德加
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
    return WORLD_9_DIR "1/npc/guard.c"; // 守卫
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME对$YOU鼓了鼓掌。" NOR,
        CYN "$ME对$YOU说：恭喜你，我们的勇者，现在更多的冒险等你探索，世界的和平等你守护。" NOR,
        HIC "$ME对$YOU说：去圣修塔因城[坐标(-72,20,11)]看看吧，国王在召唤你。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：1000\n金币：100\n";
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
    REWARD_D->bonus(player, 1000, 100);
}
