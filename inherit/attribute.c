// 角色属性接口ATTRIBUTE
#include <dbase.h>

// 设置属性值
int set_attr(string attr, int value)
{
    return set("attr/" + attr, value);
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
    return query_attr("str");
}
// 敏捷
int query_agi()
{
    return query_attr("agi");
}
// 体格
int query_vit()
{
    return query_attr("vit");
}
// 智力
int query_int()
{
    return query_attr("int");
}
// 灵巧
int query_dex()
{
    return query_attr("dex");
}
// 幸运
int query_luk()
{
    return query_attr("luk");
}

// 最大HP
int query_max_hp()
{
    return query_attr("max_hp") + query_vit() * 10;
}
// 最大MP
int query_max_mp()
{
    return query_attr("max_mp") + query_int() * 5;
}
// 当前HP
int query_hp()
{
    return query_attr("hp");
}
// 当前MP
int query_mp()
{
    return query_attr("mp");
}

// 攻击
int query_attack()
{
    return query_str() * 8 + query_luk() / 5;
}
// 防御
int query_defense()
{
    return query_vit() * 2;
}
// 法术攻击
int query_m_attack()
{
    return query_int() * 6 + query_luk() / 5;
}
// 法术防御
int query_m_defense()
{
    return query_int() / 2;
}
// 体力恢复力
int query_hp_mend()
{
    return query_vit() / 5;
}
// 灵力恢复力
int query_mp_mend()
{
    return query_int() / 3;
}
//恢复力
int query_mend()
{
    return query_hp_mend() + query_mp_mend();
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
