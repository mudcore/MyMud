nosave mapping skill_info = ([
    "name" : "wand", // 技能名称
    "type" : TYPE_X, // 伤害类型
    "range" : RANGE_S, // 作用范围
    "lv" : ({
         (["max_mp" : 5]),
         (["max_mp" : 10]),
         (["max_mp" : 15]),
         (["mp_rate" : 0.05]), // 魔力吸收率
         (["max_mp" : 20]),
         (["max_mp" : 30]),
         (["mp_rate" : 0.05]),  // 魔力吸收率
         (["max_mp" : 50]),
         (["mp_regen" : 10]), // 回复魔力数值random(mp_regen);
         ([]),
    })
]);

#include "skill.h"
