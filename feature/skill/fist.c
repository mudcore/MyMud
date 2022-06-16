nosave mapping skill_info = ([
    "name" : "fist", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["dodge" : 0.05]),
         (["damage" : 10]),
         (["critical" : 0.05]), // 会心几率5%
         (["damage" : 15]),
         (["damage" : 20]),
         (["critical" : 0.1]),
         (["damage" : 30]),
         ([]),
         (["damage" : 60]),
    })
]);

#include "skill.h"
