/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: attribute.c
Description: 角色属性接口 ATTRIBUTE 获取角色综合能力数字
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <buff.h>
#include <dbase.h>

// 设置属性值
int set_attr(string attr, int value)
{
    return set("attr/" + attr, value);
}
// 设置属性列表(生命、魔力、攻、防、速)
varargs int set_attrs(int max_hp, int max_mp, int str, int vit, int agi)
{
    set_attr("max_hp", max_hp);
    set_attr("max_mp", max_mp);
    set_attr("str", str);
    set_attr("vit", vit);
    set_attr("agi", agi);
}
// 更新属性值
int add_attr(string attr, int value)
{
    return add("attr/" + attr, value);
}
// 获取属性值
int query_attr(string attr)
{
    return query("attr/" + attr);
}

// 力量
int query_str()
{
    return query_attr("str") + query("gift/str") + query(BUFF_STR) + query_temp(BUFF_STR);
}
// 速度
int query_agi()
{
    return query_attr("agi") + query("gift/agi") + query(BUFF_AGI) + query_temp(BUFF_AGI);
}
// 耐力
int query_vit()
{
    return query_attr("vit") + query("gift/vit") + query(BUFF_VIT) + query_temp(BUFF_VIT);
}
// 幸运
int query_luk()
{
    return query_attr("luk") + query("gift/luk") + query(BUFF_LUK) + query_temp(BUFF_LUK);
}
// 魅力
int query_charm()
{
    return query_attr("charm") + query("gift/charm") + query(BUFF_CHARM) + query_temp(BUFF_CHARM);
}
// 回复魔力
int query_mend()
{
    return query_attr("mend") + query("gift/mend") + query(BUFF_MEND) + query_temp(BUFF_MEND);
}
// 攻击魔力
int query_magic()
{
    return query_attr("int") + query("gift/int") + query(BUFF_INT) + query_temp(BUFF_INT);
}

int query_max_hp() // 最大HP
{
    return query_attr("max_hp") + query("gift/max_hp") + query(BUFF_MAX_HP) + query_temp(BUFF_MAX_HP);
}

int query_max_mp() // 最大MP
{
    return query_attr("max_mp") + query("gift/max_mp") + query(BUFF_MAX_MP) + query_temp(BUFF_MAX_MP);
}

int query_hp() // 当前HP
{
    return query_attr("hp");
}

int query_mp() // 当前MP
{
    return query_attr("mp");
}

int query_max_sp() // 拥有技能点
{
    return query_attr("sp");
}

int query_sp() // 可用技能点
{
    mapping sp = query("skill/sp");
    if (mapp(sp))
        return query_attr("sp") - sp["sk1"] - sp["sk2"] - sp["sk3"] - sp["sk4"] - sp["sk5"];
    else
        return query_attr("sp");
}

// 攻击
int query_attack()
{
    return query_str() + query(BUFF_DAMAGE) + query_temp(BUFF_DAMAGE);
}
// 防御
int query_defense()
{
    return query_vit() + query(BUFF_DEFENSE) + query_temp(BUFF_DEFENSE);
}
// 格挡率
float query_parry()
{
    return query(BUFF_PARRY) + query_temp(BUFF_PARRY);
}
// 躲闪率
float query_dodge()
{
    return query(BUFF_DODGE) + query_temp(BUFF_DODGE) + query_agi() / 10000.0 + query_charm() / 10000.0;
}
// 魔法吸收率
float query_mp_rate()
{
    return query(BUFF_MP_RATE) + query_temp(BUFF_MP_RATE);
}
// 会心几率
float query_critical()
{
    return query(BUFF_CRITICAL) + query_temp(BUFF_CRITICAL) + query_luk() / 10000.0;
}
// 克制魔物系列
int query_fm()
{
    return query_temp(BUFF_FAMILY);
}

// 综合属性
varargs int query_score(int i)
{
    int sc1 = query_str() + query_agi() + query_vit() + query_luk() + query_charm() + query_magic() + query_mend();
    int sc2 = query_max_hp() + query_max_mp();
    int sc3 = query_attack() + query_defense();
    int sc = sc1 + sc2 + sc3;
    switch (i)
    {
    case 1:
        return sc1;
    case 2:
        return sc2;
    case 3:
        return sc3;
    default:
        return sc;
    }
}
// 恢复
int set_hp_full() { return set_attr("hp", query_max_hp()); }
int set_mp_full() { return set_attr("mp", query_max_mp()); }
void set_all_full()
{
    set_hp_full();
    set_mp_full();
}
// 清零(die)
int set_hp_zero() { return set_attr("hp", 0); }
int set_mp_zero() { return set_attr("mp", 0); }
void set_all_zero()
{
    set_hp_zero();
    set_mp_zero();
}
// 判断
int is_hp_full() { return query_hp() >= query_max_hp(); }
int is_mp_full() { return query_mp() >= query_max_mp(); }
int is_all_full()
{
    return is_hp_full() && is_mp_full();
}
// 攻击吸血
int hp_regen()
{
    return query_temp(BUFF_HP_REGEN);
}
// 魔杖回魔
int mp_regen()
{
    return random(query_temp(BUFF_MP_REGEN));
}
