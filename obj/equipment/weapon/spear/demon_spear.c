inherit STD_SPEAR;

void create()
{
    ::create();
    set_name("恶魔矛", ({"demon spear", "spear"}));
    set("long", "使用恶魔心核炼制的长枪，具有极强的杀伤力。");
    add("equip_info", ([
        "lv" : 50, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 93,
        "critical" : 0.08,
    ]) );
    set("base_value", 450); // 卖给ＮＰＣ
    set("value", 45000); // 从ＮＰＣ购买
}
