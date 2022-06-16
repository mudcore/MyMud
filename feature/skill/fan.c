nosave mapping skill_info = ([
    "name" : "fan", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_ELEMENTAL]),
         (["damage" : 5]),
         (["critical" : 0.03]), // 会心几率3%
         (["damage" : 10]),
         (["damage" : 15]),
         (["dodge" : 0.15]),
         (["damage" : 20]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
