nosave mapping skill_info = ([
    "name" : "claw", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_MACHINE]),
         (["damage" : 5]),
         (["critical" : 0.03]), // 会心几率3%
         (["damage" : 10]),
         (["damage" : 15]),
         (["critical" : 0.1]),
         (["damage" : 20]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
