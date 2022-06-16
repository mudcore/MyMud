nosave mapping skill_info = ([
    "name" : "sword", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_DRAGON]), // 克制系列
         (["damage" : 5]),
         (["critical" : 0.03]), // 会心几率3%
         (["damage" : 10]),
         (["damage" : 15]),
         ([]),
         (["damage" : 20]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
