#ifndef COMBAT_H
#define COMBAT_H

// 技能类型
#define TYPE_X 1 // 被动技能
#define TYPE_B 2 // 增益咒文
#define TYPE_H 3 // 回复咒文
#define TYPE_M 4 // 攻击咒文
#define TYPE_S 5 // 职业特技
#define TYPE_O 6 // 其它咒文

// 伤害状态类型
#define TYPE_N 0x10 // 普通攻击
#define TYPE_C 0x20 // 会心一击
#define TYPE_D 0x40 // 躲闪攻击
#define TYPE_P 0x80 // 格挡攻击

// 攻击范围
#define RANGE_S 1 // 单体固定
#define RANGE_R 2 // 单体随机
#define RANGE_G 4 // 小组
#define RANGE_A 8 // 全体

// 战斗回合
#define ROUND_ATTACK 1 // 攻击回合
#define ROUND_WAIT 2 // 等待回合
#endif
