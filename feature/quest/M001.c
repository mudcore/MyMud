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
// 此任务可否放弃
int noGiveUp() { return 1; }

// 任務名稱
string getName()
{
    return HIY"星空的守护者"NOR;
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "到人间冒险，拯救这个世界。\n";

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
    return WORLD_DIR "npc/ivy.c"; // 大天使·艾薇
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "新来的天使呀，女神为了封印魔神陷入了沉睡，现在世界有新的暗黑力量在觉醒。" NOR,
        "$ME对$YOU說道：" HIG "是时候去守护这个世界了，请到人间，帮助人类并寻找守护的力量吧。" NOR,
        "$ME对$YOU說道：" HIG "哪怕现在的你还很弱小，但相信爱与守护的力量，找到你的同伴，世界需要你的拯救。" NOR,
    });
    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill()
{
    return ([
        MOB_DIR "9/261.c" : 1, // 魔神贾达玛
        MOB_DIR "9/274.c" : 1, // 暗黑皇帝伽纳撒旦
        MOB_DIR "9/277.c" : 1, // 堕天使艾尔基奥斯
        MOB_DIR "9/291.c" : 1, // 邪眼皇帝阿瓦特
        MOB_DIR "9/292.c" : 1, // 魔神剑雷帕鲁德
        MOB_DIR "9/293.c" : 1, // 破坏神弗洛波斯
        MOB_DIR "9/299.c" : 1, // 死亡皮萨罗
        MOB_DIR "9/303.c" : 1, // 死亡塔姆亚
        MOB_DIR "9/304.c" : 1, // 暗黑多雷安
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
    return WORLD_DIR "npc/ivy.c"; // 大天使·艾薇
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME满意的看着$YOU。" NOR,
        HIY "$ME对$YOU说：恭喜你拯救了我们的世界，现在你就是这片星空的守护者，新的冒险在等着你。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "未知奖励\n";
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
    string title = HIY"星空的守护者"NOR;
    player->set_title(title, time());
    tell_object(player, "你获得了新的称号「" + title + "」。\n");
    REWARD_D->bonus(player, 100000, 100000);
}
