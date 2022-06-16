inherit STD_WAND;

void create()
{
    ::create();
    set_name("贤者之杖", ({"sage staff", "staff", "wand"}));
    set("long", "贤者使用的魔杖，制作精良，具有很强的魔力。");
    add("equip_info", ([
        "lv" : 50, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 73,
        "int" : 12,
        "mp_rate" : 0.08, // MP吸收率
    ]) );
    set("base_value", 500); // 卖给ＮＰＣ
    set("value", 40000); // 从ＮＰＣ购买
}
