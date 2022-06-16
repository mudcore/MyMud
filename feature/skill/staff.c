nosave mapping skill_info = ([
    "name" : "staff", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["damage" : 5]),
         (["family" : M_ZOMBIE]),
         (["damage" : 5]),
         (["dodge" : 0.05]), // 躲闪率5%
         (["damage" : 10]),
         (["damage" : 15]),
         (["critical" : 0.1]),
         (["damage" : 20]),
         ([]),
         ([]),
    })
]);

#include "skill.h"
