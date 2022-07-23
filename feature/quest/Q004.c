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
    return "乐善好施";
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "冒险总是危险的，特别是在准备不足的时候，没有魔力就失去了战斗能力。\n";
    msg += "给基萨格纳遗迹入口受伤的冒险者三瓶魔法圣水吧。\n";

    return msg;
}

// 任務等級
int getLevel()
{
    return 5;
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
    return player->query("lv") >= getLevel() && player->isSolved(F_QUEST("Q002"));
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "2/npc/adventurer.c"; // 受伤的冒险者
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "我现在受伤行动不太方便，你能给我3瓶魔法圣水吗？" NOR,
        "$ME对$YOU說道：" HIG "消灭遗迹里的梅拉鬼魂有几率获得魔法圣水，不过一定要注意安全，这魔物会魔法。" NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill()
{
    return ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
mapping getItem()
{
    return ([
        ITEM_DIR "magic_water.c" : 3, // 魔法圣水3瓶
    ]);
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
    return WORLD_9_DIR "2/npc/adventurer.c"; // 受伤的冒险者
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME非常感谢$YOU。" NOR,
        HIG "$ME对$YOU说：太感谢了，你知道吗，在遗迹里以前有个很强的魔物，后来被大家封印了，现在成为冒险者试炼的挑战。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：2000\n金币：1000\n";
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
    REWARD_D->bonus(player, 2000, 1000);
}
