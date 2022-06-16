```c
inherit STD_WEAPON;

int is_sword() { return 1; }

void create()
{
    ::create();
    set_name("柏木剑", ({"rod"}));
    set("long", "用柏木削成的普通木剑");
    set("unit", "把");
    set("equip_info", ([
        "type" : "weapon", // 装备类型
        "weapon" : "sword", // 武器类型
        "vocation" : ({ "common", "warrior", "minstrel", // 职业限制
                        "thief", "gladiator" , "armament-alist" }),
        "gender" : 0, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 4,
        "double" : 1, // 连击几率
        "poison" : 5, // 中毒几率
        "family" : M_ZOMBIE, // 克制僵尸系魔物
    ]) );
    set("base_value", 10); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
```
