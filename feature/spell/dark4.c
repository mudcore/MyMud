/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: dark4.c
Description:暗系魔法，单体伤害
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
/**
 * 小于咒语固有魔攻时伤害直接是[初始值]
 * 大于固有魔攻时伤害是[初始值]+(魔攻-固有魔攻)×增长率
 * [实际伤害值]=[伤害计算值]=(max([初始值],[初始值]+(魔攻-固有魔攻)×增长率)×蓄力倍率)+(等级/10+1)×蓄力次数)×魔防倍率×属性倍率×其他倍率
 */
nosave mapping spell_info = ([
    "name" : "dark4", // 咒文名称
    "type" : TYPE_M, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "base" : 480, // 基础值(固有魔攻)
    "min"  : 255, // 最小伤害
    "rand" : 60, // 最大波动值 255 + random(60) = 314
    "rate" : 0.636, // 增长率
    "max"  : 2999, // 伤害上限
    "mp"   : 45, // 魔力消耗
]);

#include "type_m_s.h"
