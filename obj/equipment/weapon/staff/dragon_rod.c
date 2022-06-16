inherit STD_STAFF;

void create()
{
    ::create();
    set_name("降龙棍", ({"dragon rod", "rod", "staff"}));
    set("long", "传说中屠龙勇士用过的武器，对龙类魔物伤害增加20%。");
    add("equip_info", ([
        "lv" : 50, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 111,
        "family" : M_DRAGON, // 克制龙系
    ]) );
    set("base_value", 500); // 卖给ＮＰＣ
    set("value", 40000); // 从ＮＰＣ购买
}
