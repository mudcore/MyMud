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
    return "与人为善";
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "冒险总是危险的，旅店的冒险者受伤了，给他准备一些草药吧。\n";

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
    return player->isSolved(F_QUEST("Q001"));
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "1/npc/adventurer.c"; // 受伤的冒险者
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "我现在受伤行动不太方便，你能帮我弄3株药草吗？" NOR,
        "$ME对$YOU說道：" HIG "你可以去杂货铺，在那里可以买卖装备和物品。" NOR,
        "$ME对$YOU說道：" HIG "如果你没有钱，可以去村外消灭魔物，很多魔物都喜欢收集亮晶晶的金币。" NOR,
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
        ITEM_DIR "medicinal_herb.c" : 3, // 草药3株
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
    return WORLD_9_DIR "1/npc/adventurer.c"; // 受伤的冒险者
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME非常感谢$YOU。" NOR,
        HIG "$ME对$YOU说：感谢你的帮助，你知道吗？可以找教堂的神官查看自己升级所需的经验。" NOR,
        CYN "$ME对$YOU说：如果你想更强大一些，最好转职成旅艺人等职业，你会学到强力的技能(skill)和咒文(spell)。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：20\n金币：30\n";
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
    REWARD_D->bonus(player, 20, 30);
}
