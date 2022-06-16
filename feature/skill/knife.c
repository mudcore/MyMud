nosave mapping skill_info = ([
    "name" : "knife", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_BUG]),
         (["damage" : 5]),
         (["critical" : 0.05]), // 会心几率5%
         (["damage" : 10]),
         (["damage" : 10]),
         (["critical" : 0.1]),
         (["damage" : 20]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
