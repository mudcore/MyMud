// 吸血鬼之刃

nosave mapping skill_info = ([
    "name" : "z-knife", // 技能名称
    "type" : TYPE_S, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "base_rate" : 1.25, // 伤害基准倍率
    "rand" : 0.0, // 伤害倍率波动范围 1.0 ± random(0.25*100) / 100.0
    "times" : 1, // 攻击次数
    "hp_regen" : 0.25, // 吸血比例
    "mp_regen" : 0, // 吸魔比例(非魔杖物理攻击)
    "mp"   : 6, // 魔力消耗
]);

#include "skill1.h"
