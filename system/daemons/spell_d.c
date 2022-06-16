/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: spell_d.c
Description:魔法咒文系统守护进程 SPELL_D
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>

// 平民
nosave mapping spell_info0 = ([
    3 : "heal",
    // 10 : "evac",
]);
// 战士
nosave mapping spell_info1 = ([]);
// 僧侣
nosave mapping spell_info2 = ([
    1 : "heal", // 单体
    16 : "heal2", // 单体
    31 : "heal3", // 单体
    47 : "heal4", // 全体
    38 : "heal5", // 单体999
    65 : "heal6", // 全体999
    // 18 : "revive",
    // 20 : "death1", // 单体
    // 34 : "death2", // 小组
    // 55 : "death3", // 全体
    // 6 : "sleep",
    // 10 : "chaos",
]);
// 魔法师
nosave mapping spell_info3 = ([
    1 : "fire", // 单体
    30 : "fire2",
    53 : "fire3",
    64 : "fire4",
    6 : "ice", // 单体
    16 : "ice2", // 小组
    40 : "ice3",
    68 : "ice4",
    11 : "light", // 全体
    28 : "light2",
    47 : "light3",
    // 8 : "evac",
    // 19 : "chaos",
]);
// 武斗家
nosave mapping spell_info4 = ([]);
// 盗贼
nosave mapping spell_info5 = ([
    9 : "heal",
    // 12 : "evac",
]);
// 旅艺人
nosave mapping spell_info6 = ([
    3 : "heal",
    21 : "heal2",
    // 24 : "revive",
    8 : "ice", // 单体
    16 : "ice2", // 小组
    12 : "wind", // 小组
    30 : "wind2", // 小组
    36 : "wind3", // 小组
    // 10 : "evac",
]);
// 战斗大师
nosave mapping spell_info7 = ([]);
// 圣骑士
nosave mapping spell_info8 = ([
    7 : "heal",
    20 : "heal2",
]);
// 魔法战士
nosave mapping spell_info9 = ([
    // 8 : "sleep1",
    // 28 : "sleep2",
    // 20 : "chaos1",
    // 31 : "chaos2",
    // 10 : "zoom",
]);
// 游侠
nosave mapping spell_info10 = ([
    10 : "heal",
    22 : "heal2",
    // 34 : "heal3",
]);
// 贤者
nosave mapping spell_info11 = ([
    2 : "heal",
    16 : "heal2",
    33 : "heal3",
    33 : "heal4",
    2 : "dark",
    8 : "dark2",
    43 : "dark3",
    61 : "dark4",
    8 : "light",
    27 : "light2",
    48 : "light3",
    66 : "light4",
    // 78 : "boom",
]);
// 超级明星
nosave mapping spell_info12 = ([
    4 : "heal",
    23 : "heal2",
    11 : "wind",
    36 : "wind2",
    45 : "wind3",
    58 : "wind4",
]);

void learn_spell(object me)
{
    mapping spell_info;
    int *level, voc = me->query("vocation"), lv = me->query("lv");

    switch (voc) {
        case "warrior":
            spell_info = spell_info1;
            break;
        case "priest":
            spell_info = spell_info2;
            break;
        case "mage":
            spell_info = spell_info3;
            break;
        case "martial-artist":
            spell_info = spell_info4;
            break;
        case "thief":
            spell_info = spell_info5;
            break;
        case "minstrel":
            spell_info = spell_info6;
            break;
        case "gladiator":
            spell_info = spell_info7;
            break;
        case "paladin":
            spell_info = spell_info8;
            break;
        case "armament-alist":
            spell_info = spell_info9;
            break;
        case "ranger":
            spell_info = spell_info10;
            break;
        case "sage":
            spell_info = spell_info11;
            break;
        case "luminary":
            spell_info = spell_info12;
            break;
        default:
            spell_info = spell_info0;
    }
    level = sort_array(keys(spell_info), 1);
    foreach(int lvl in level)
    {
        if (lvl <= lv)
        {
            if (!me->query_spell(spell_info[lvl]))
            {
                me->set_spell(spell_info[lvl], 1);
                tell_object(me, HIM "你学会了新的魔法咒文「" + chinese(spell_info[lvl]) + "」[咒语：cast " + spell_info[lvl] + "]。\n" NOR);
            }
        } else
            break;
    }
}
