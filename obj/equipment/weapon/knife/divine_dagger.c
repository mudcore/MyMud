inherit STD_KNIFE;

void create()
{
    ::create();
    set_name("神圣小刀", ({"divine dagger", "knife", "dagger"}));
    set("long", "一把被圣水圣化过的银白色利器，对僵尸系魔物伤害提高20%。");
    add("equip_info", ([
        "lv" : 15, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 18,
        "family" : M_ZOMBIE, // 克制僵尸系魔物
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 850); // 从ＮＰＣ购买
}
