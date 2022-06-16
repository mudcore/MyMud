nosave mapping skill_info = ([
    "name" : "axe", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_PLANT]),
         (["damage" : 10]),
         (["critical" : 0.03]), // 会心几率3%
         (["damage" : 15]),
         (["damage" : 20]),
         (["critical" : 0.07]),
         (["damage" : 30]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
