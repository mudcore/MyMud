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
    return "日行一善";
}

// 任務描述
string getDetail()
{
    string msg;

    msg = "勿以善小而不为，勿以恶小而为之。\n";
    msg += "做为普通人，哪怕日行一善，也能为我们的世界对抗魔物的破坏做出巨大的贡献。\n";
    msg += "沃尔罗村教堂里的牧师达林在帮助大家，但也需要大家的帮助。\n";
    msg += "捐助医疗草药给牧师达林。\n";

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
    return player->query("lv") >= getLevel();
}

// 接受任務的NPC (以檔名來識別)
string getAssigner()
{
    return WORLD_9_DIR "1/npc/darling.c"; // 牧师达林
}

// 接受任務時的訊息
string *getAssignMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        "$ME对$YOU說道：" HIG "你好，冒险者，治疗受伤的村民需要大量的草药，你能捐助一些吗？" NOR,
        "$ME对$YOU說道：" HIG "现在我需要草药10个，医疗草5个，帮我收集一些吧。" NOR,
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
        ITEM_DIR "medicinal_herb.c" : 10, // 草药10株
        ITEM_DIR "rose_root.c" : 5, // 医疗草5株
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
    return WORLD_9_DIR "1/npc/darling.c"; // 牧师达林
}

// 完成任務時的訊息
string *getRewardMessage()
{
    // $ME為NPC, $YOU為player
    string *msg = ({
        CYN "$ME非常感谢$YOU的捐助。" NOR,
        CYN "$ME对$YOU说：谢谢你的帮助，女神会护佑着你的，希望你在以后的冒险中也能的助人为乐。" NOR,
        HIC "$ME对$YOU说：我把这瓶圣水和一对奇美拉之翼送给你，希望对你的冒险有帮助。" NOR,
    });
    return msg;
}

string getReward()
{
    string msg = "经验：1000\n称号：助人为乐\n物品：圣水1瓶、奇美拉之翼1枚\n";
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
    mapping items = ([
        ITEM_DIR "holy_water.c" : 1,
        ITEM_DIR "chimaera_wing.c" : 1,
    ]);
    string title = HIG"助人为乐"NOR;
    player->set_title(title, time());
    tell_object(player, "你获得了新的称号「" + title + "」。\n");
    foreach(string item, int amount in items)
    {
        object ob;
        ob = new (item);
        ob->set_amount(amount);
        ob->move(player);
        msg("vision","$ME拿出" + ob->short() + "给$YOU。", npc, player);
    }
    REWARD_D->bonus(player, 1000);
}
