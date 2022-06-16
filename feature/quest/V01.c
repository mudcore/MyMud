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
    return HIC"旅艺人的冒险"NOR;
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "去基萨格纳遗迹的转职之间转职成为旅艺人。\n";
    msg += "旅艺人是游戏中相对平衡一个职业，战斗技能和魔法技能都有一定的掌握。\n";
    msg += "旅艺人可以无视性别限制的使用装备，而且拥有神奇的旅艺人背包。\n";
    msg += "旅艺人可精通剑、鞭、扇、盾四系装备。\n";

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
    return player->query("lv") >= getLevel();
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "1/npc/minstrel.c"; // 旅艺人布丁
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "你也想成为旅艺人吗？可以去基萨格纳遗迹，找到转职之间，完成转职。" NOR,
        "$ME对$YOU說道：" HIG "遗迹的入口在村外坐标(-105,15)的位置，但作为挑战，我不会告诉你转职之间的坐标，自己去寻找吧。" NOR,
        "$ME对$YOU說道：" HIG "完成转职后再回来找我，我会给你丰厚的奖励哦。" NOR,
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
    return ([]);
}

// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    return player->query("vocation") == "minstrel";
}

// 完成任務的NPC (以檔名來識別)
string getRewarder()
{
    return WORLD_9_DIR "1/npc/minstrel.c"; // 旅艺人布丁
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME对$YOU说：恭喜你成为旅艺人，拥有背包后旅途会更便利了吧？" NOR,
        HIG "$ME对$YOU说：做为冒险家，一定要去圣修塔因城旅行哦，那里的国王好像最近有发布悬赏任务，很多冒险者都去了。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：1000\n金币：200\n";
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
    REWARD_D->bonus(player, 1000, 200);
}
