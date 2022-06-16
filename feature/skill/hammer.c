nosave mapping skill_info = ([
    "name" : "hammer", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_MATERIAL]),
         (["damage" : 10]),
         (["critical" : 0.03]), // 会心几率3%
         (["damage" : 15]),
         (["damage" : 20]),
         (["critical" : 0.1]),
         (["damage" : 30]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
