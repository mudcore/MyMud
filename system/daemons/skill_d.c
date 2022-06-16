/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: skill_d.c
Description:技能系统守护进程 SKILL_D
Author: xuefeng
Version: v1.0
Date: 2019-03-29
History:
*****************************************************************************/
#include <ansi.h>
// 技能：ＳＰ - 名称 - 说明 - 等级 - 称号
/**
 * 武器技能
 */
 nosave mapping sword_skill = ([
      3:({"sword", "装备剑时攻击力额外+5。", 1, "用剑的人"}),
      7:({"sword", "装备剑时对龙系魔物伤害提高50%。", 2}),
     13:({"sword", "装备剑时攻击力额外+5。", 3}),
     22:({"sword", "装备剑时会心率增加3%。", 4, "有名的剑士"}),
     35:({"sword", "装备剑时攻击力额外+10。", 5}),
     42:({"sword", "装备剑时攻击力额外+15。", 6}),
     58:({"z-sword", "对敌造成75%伤害的攻击，使用者恢复伤害值25%的HP。", 1, "剑豪"}),
     76:({"sword", "装备剑时攻击力额外+20。", 8}),
     88:({"x-sword", "对敌一组造成75%~125%的伤害。", 1}),
    100:({"sword", "该角色全部职业都可以装备剑。", 10, "剑神"}),
]);

nosave mapping spear_skill = ([
      3:({"spear", "装备枪时攻击力额外+5。", 1, "用枪的人"}),
      7:({"spear", "装备枪时对兽系怪物伤害提高50%。", 2}),
     13:({"spear", "装备枪时攻击力额外+5。", 3}),
     22:({"spear", "装备枪时会心率上升3%。", 4, "有名的枪手"}),
     35:({"spear", "装备枪时攻击力额外+10。", 5}),
     42:({"spear", "装备枪时攻击力额外+15。", 6}),
     58:({"spear", "装备枪时会心率上升7%。", 7, "星之枪手"}),
     76:({"spear", "装备枪时攻击力额外+20。", 8}),
     88:({"x-spear", "以50%的伤害对随机敌人作出5次连续攻击。", 1}),
    100:({"spear", "该角色全部职业都可以装备枪。", 10, "枪神"}),
]);

nosave mapping knife_skill = ([
      3:({"knife", "装备短剑时攻击力额外+5。", 1, "用短剑的人"}),
      7:({"knife", "装备短剑时对虫系怪物伤害提高50%。", 2}),
     13:({"knife", "装备短剑时攻击力数值额外+5。", 3}),
     22:({"knife", "装备短剑时会心率上升5%。", 4, "刺客"}),
     35:({"knife", "装备短剑时攻击力数值额外+10。", 5}),
     42:({"knife", "装备短剑时攻击力数值额外+10。", 6}),
     58:({"knife", "装备短剑时会心率上升10%。", 7, "沉默杀手"}),
     76:({"knife", "装备短剑时攻击力数值额外+20。", 8}),
     88:({"z-knife", "附带HP吸收效果的普通攻击，使用者HP恢复伤害值的25%。", 1}),
    100:({"knife", "该角色全部职业都可以装备短剑。", 10, "刺客之王"}),
]);

nosave mapping wand_skill = ([
      3:({"wand", "装备杖时最大MP数值额外+5。", 1, "零之使魔"}),
      7:({"wand", "装备杖是最大MP数值额外+10。", 2}),
     13:({"wand", "装备杖是最大MP数值额外+15", 3}),
     21:({"wand", "装备杖时MP吸收率上升5%。", 4, "驱魔杖使者"}),
     31:({"wand", "装备杖时最大MP数值额外+20。", 5}),
     44:({"wand", "装备杖是最大MP数值额外+30。", 6}),
     57:({"wand", "装备杖时MP吸收率上升10%。", 7, "祝福杖使者"}),
     70:({"wand", "装备杖时最大MP数值额外+30。", 8}),
     84:({"wand", "装备杖时MP吸收固定增加数点。", 9}),
    100:({"wand", "该角色全部职业都可以装备杖。", 10, "神圣杖使者"}),
]);

nosave mapping whip_skill = ([
      3:({"whip", "装备鞭时攻击力额外+5。", 1, "用鞭的人"}),
      7:({"whip", "装备鞭时对怪人系怪物伤害提高50%。", 2}),
     13:({"whip", "鞭装备时攻击力数值额外+5。", 3}),
     22:({"whip", "装备鞭时会心率上升3%", 4, "偶像鞭手"}),
     35:({"whip", "鞭装备时攻击力额外+10。", 5}),
     42:({"whip", "装备鞭时攻击力额外+15。", 6}),
     58:({"whip", "装备鞭时会心率上升10%。", 7, "明星鞭手"}),
     76:({"whip", "装备鞭时攻击力额外+20。", 8}),
     88:({"z-whip", "对敌一组攻击，使用者HP恢复对一个敌人伤害的25%，伤害不会渐减。", 1}),
    100:({"whip", "该角色全部职业都可以装备鞭。", 10, "传说的鞭手"}),
]);

nosave mapping staff_skill = ([
      3:({"staff", "装备棍时攻击力额外+5。", 1, "用棍的人"}),
      7:({"staff", "装备棍是对僵尸系怪物伤害提高50%。", 2}),
     13:({"staff", "装备棍是攻击力额外+5", 3}),
     22:({"staff", "棍装备时躲闪率上升5%。", 4, "疾风棍手"}),
     35:({"staff", "装备棍时攻击力额外+10。", 5}),
     42:({"staff", "装备棍时攻击力额外+15。", 6}),
     58:({"staff", "棍装备时会心率上升10%。", 7, "星之棍手"}),
     76:({"staff", "棍装备时攻击力数值额外+20。", 8}),
     88:({"x-staff", "以50%的伤害对随机敌人作出5次连续攻击。", 1}),
    100:({"staff", "该角色全部职业都可以装备棍。", 10, "疯魔棍神"}),
]);

nosave mapping claw_skill = ([
      3:({"claw", "装备爪时攻击力额外+5。", 1, "用爪的人"}),
      7:({"claw", "装备爪时对机械系怪物伤害提高50%。", 2}),
     13:({"claw", "装备爪时攻击力额外+5。", 3}),
     22:({"claw", "装备爪时会心率上升3%。", 4, "切斩之鹰"}),
     35:({"claw", "装备爪时攻击力额外+10。", 5}),
     42:({"claw", "装备爪时攻击力额外+15。", 6}),
     58:({"claw", "装备爪时会心率上升10%。", 7, "摘星爪"}),
     76:({"claw", "装备爪时攻击力额外+20。", 8}),
     88:({"x-claw", "以50%~150%的伤害对敌单体做出4回连续攻击。", 1}),
    100:({"claw", "该角色全部职业都可以装备爪。", 10, "切裂之星"}),
]);

nosave mapping fan_skill = ([
      3:({"fan", "装备扇时攻击力数值额外+5。", 1, "微风使者"}),
      7:({"fan", "装备扇时对元素系怪物伤害提高50%。", 2}),
     13:({"fan", "装备扇时攻击力数值额外+5。", 3}),
     22:({"fan", "装备扇时会心率上升3%。", 4, "读风师"}),
     35:({"fan", "装备扇时攻击力数值额外+10。", 5}),
     42:({"fan", "装备扇时攻击力数值额外+15。", 6}),
     58:({"fan", "装备扇时躲闪率上升15%。", 7, "风之舞者"}),
     76:({"fan", "扇装备时攻击力数值额外+20。", 8}),
     88:({"x-fan", "以50%~150%的伤害对随机敌人作出4次连续攻击。", 1}),
    100:({"fan", "该角色全部职业都可以装备扇。", 10, "风之仙人"}),
]);

nosave mapping axe_skill = ([
      3:({"axe", "装备斧时攻击力额外+5。", 1, "使用斧的人"}),
      7:({"axe", "装备斧时对植物系怪物伤害提高50%。", 2}),
     13:({"axe", "装备斧时攻击力额外+10", 3}),
     22:({"axe", "装备斧时会心率上升3%。", 4, "收割者"}),
     35:({"axe", "装备斧时攻击力额外+15", 5}),
     42:({"axe", "装备斧时攻击力额外+20。", 6}),
     58:({"axe", "装备斧时会心率上升7%。", 7, "毁灭者"}),
     76:({"axe", "装备斧时攻击力额外+30。", 8}),
     88:({"x-axe", "以80%~120%伤害攻击一组敌人。", 1}),
    100:({"axe", "该角色全部职业都可以装备斧。", 10, "斩佛大魔神"}),
]);

nosave mapping hammer_skill = ([
      3:({"hammer", "装备锤时攻击力额外+5。", 1, "用锤的人"}),
      7:({"hammer", "装备锤时对物质系怪物伤害提高50%。", 2}),
     13:({"hammer", "装备锤时攻击力额外+10。", 3}),
     22:({"hammer", "装备锤时会心率上升3%。", 4, "战斗破坏者"}),
     35:({"hammer", "装备锤时攻击力额外+15。", 5}),
     42:({"hammer", "装备锤时攻击力额外+20。", 6}),
     58:({"hammer", "装备锤时会心率上升10%。", 7, "百万吨战士"}),
     76:({"hammer", "装备锤时攻击力额外+30。", 8}),
     88:({"x-hammer", "以150%的伤害对敌全体做出攻击。", 1}),
    100:({"hammer", "该角色全部职业都可以装备锤。", 10, "破坏神"}),
]);

nosave mapping boomerang_skill = ([
      3:({"boomerang", "装备回旋镖时攻击力额外+5。", 1, "用镖的人"}),
      7:({"boomerang", "装备镖时对史莱姆系怪物伤害提高50%。", 2}),
     13:({"boomerang", "装备回旋镖时攻击力额外+5。", 3}),
     22:({"boomerang", "装备回旋镖时会心率上升5%。", 4, "投掷明星"}),
     35:({"boomerang", "装备回旋镖时攻击力额外+10。", 5}),
     42:({"boomerang", "装备回旋镖时攻击力额外+15。", 6}),
     58:({"boomerang", "装备回旋镖时会心率上升10%。", 7, "战斗龙卷风"}),
     76:({"boomerang", "装备回旋镖时攻击力额外+20。", 8}),
     88:({"x-boomerang", "以50%的伤害对随机敌人做出7回连续攻击。", 1}),
    100:({"boomerang", "该角色全部职业都可以装备回旋镖。", 10, "回旋镖之王"}),
]);

nosave mapping bow_skill = ([
      3:({"bow", "装备弓时攻击力额外+5。", 1, "用弓的人"}),
      7:({"bow", "装备弓时对鸟系怪物伤害提高50%。", 2}),
     13:({"bow", "装备弓时攻击力额外+5。", 3}),
     22:({"bow", "装备弓时会心率上升5%。", 4, "狙击手"}),
     35:({"bow", "装备弓时攻击力额外+10。", 5}),
     42:({"bow", "装备弓时攻击力额外+15。", 6}),
     58:({"bow", "装备弓时会心率上升10%。", 7, "神箭手"}),
     76:({"bow", "装备弓时攻击力额外+20。", 8}),
     88:({"x-bow", "以50%~150%的伤害对随机敌人做出6回连续攻击。", 9}),
    100:({"bow", "该角色全部职业都可以装备弓。", 10, "后裔"}),
]);

nosave mapping shield_skill = ([
      3:({"shield", "装备盾时防御额外+5。", 1, "用盾的人"}),
      7:({"shield", "装备盾时格挡率提升2%。", 2}),
     13:({"shield", "装备盾时防御额外+5。", 3}),
     22:({"shield", "装备盾时格挡率提升2%。", 4, "防御者"}),
     35:({"shield", "装备盾时防御额外+10。", 5}),
     42:({"shield", "装备盾时防御额外+15。", 6}),
     58:({"shield", "装备盾时格挡率提升2%。", 7, "守护战士"}),
     76:({"shield", "装备盾时防御额外+20。", 8}),
     88:({"shield", "装备盾时防御额外+30。", 9}),
    100:({"shield", "该角色全部职业都可以装备盾。", 10, "守护神"}),
]);

// 空手技能
nosave mapping fist_skill = ([
      3:({"fist", "空手时攻击力额外+5。", 1, "修行者"}),
      7:({"fist", "空手时躲闪率提升5%。", 2}),
     13:({"fist", "空手时攻击力额外+10。", 3}),
     22:({"fist", "空手时会心率上升5%。", 4, "觉醒者"}),
     35:({"fist", "空手时攻击力额外+15。", 5}),
     42:({"fist", "空手时攻击力额外+20。", 6}),
     58:({"fist", "空手时会心率上升10%。", 7, "格斗王者"}),
     76:({"fist", "空手时攻击力额外+30。", 8}),
     88:({"x-fist", "以50%~150%的伤害对随机敌人做出7回合连续攻击。", 1}),
    100:({"fist", "空手时攻击力额外+60。", 10, "武神"}),
]);

/**
 * 职业技能
 */
// 战士 - 勇气
nosave mapping courage_skill = ([]);
// 贤者 - 悟道
nosave mapping enlightenment_skill = ([]);
// 战斗大师 - 斗魂
nosave mapping guts_skill = ([]);
// 僧侣 - 信仰之心
nosave mapping faith_skill = ([]);
// 武斗家 - 斗气
nosave mapping focus_skill = ([]);
// 魔法战士 - 元素之力
nosave mapping fource_skill = ([]);
// 旅艺人 - 曲艺
nosave mapping litheness_skill = ([]);
// 超级明星 - 灵气
nosave mapping nimbus_skill = ([]);
// 游侠 - 生存
nosave mapping ruggedness_skill = ([]);
// 魔法师 - 施法
nosave mapping spellcraft_skill = ([]);
// 盗贼 - 寻宝
nosave mapping treasure_skill = ([]);
// 圣骑士 - 博爱
nosave mapping valour_skill = ([]);

// 获取技能资料
mapping skill(string type)
{
    switch (type)
    {
    case "axe":
        return axe_skill;
    case "boomerang":
        return boomerang_skill;
    case "bow":
        return bow_skill;
    case "claw":
        return claw_skill;
    case "fan":
        return fan_skill;
    case "hammer":
        return hammer_skill;
    case "knife":
        return knife_skill;
    case "shield":
        return shield_skill;
    case "spear":
        return spear_skill;
    case "staff":
        return staff_skill;
    case "sword":
        return sword_skill;
    case "wand":
        return wand_skill;
    case "whip":
        return whip_skill;
    case "fist":
        return fist_skill;
    case "courage":
        return courage_skill;
    case "enlightenment":
        return enlightenment_skill;
    case "guts":
        return guts_skill;
    case "faith":
        return faith_skill;
    case "focus":
        return focus_skill;
    case "litheness":
        return litheness_skill;
    case "nimbus":
        return nimbus_skill;
    case "ruggedness":
        return ruggedness_skill;
    case "spellcraft":
        return spellcraft_skill;
    case "treasure":
        return treasure_skill;
    case "valour":
        return valour_skill;
    default:
        return 0;
    }
}

// 学习技能
void learn_skill(object me, int sk)
{
    mapping vocation_info, skill_info;
    string *myskill, skill, title;
    int *sp, lv;
    object equip;
    // 获取当前职业技能信息
    vocation_info = VOCATION_D->vocation_info(me->query("vocation"));
    myskill = vocation_info["skill"];
    skill_info = skill(myskill[sk]);
    sp = sort_array(keys(skill_info), 1);

    foreach (int lvl in sp)
    {
        if (lvl <= me->query("skill/" + myskill[sk]))
        {
            skill = skill_info[lvl][0];
            lv = skill_info[lvl][2];
            if (!bitCheck(me->query_skill(skill), lv))
            {
                if (skill != myskill[sk])
                    tell_object(me, HIY "你学会了新的技能「" + chinese(skill) + "」(" + skill + ")。\n" NOR);
                else
                {
                    tell_object(me, HIY "你学会了新的「" + chinese(skill) + "」类被动技能。\n" NOR);
                }
            }
            me->set_skill(skill, bitSet(me->query_skill(skill), lv));
            if (sizeof(skill_info[lvl]) == 4 && !me->query_title(title = skill_info[lvl][3]))
            {
                me->set_title(title, time());
                tell_object(me, HIM "你获得了新的称号「" + title + "」。\n" NOR);
            }
        }
        else
            break;
    }
    // 盾牌被动技能效果
    if (objectp(me->query_temp("equip/shield")))
        me->skill_effect("shield", 1);
    // 武器被动技能效果
    if (objectp(equip = me->query_temp("equip/weapon")) && equip->query("equip_info")["weapon"])
        me->weapon_effect(equip->query("equip_info")["weapon"], 1);
    else
        me->skill_effect("fist", 1);
}
