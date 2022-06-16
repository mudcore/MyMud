inherit STD_HAMMER;

void create()
{
    ::create();
    set_name("战锤", ({"war hammer", "hammer"}));
    set("long", "战争使用的武器，砸中非死即伤。");
    set("unit", "柄");
    add("equip_info", ([
        "lv" : 40, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 55,
    ]) );
    set("base_value", 550); // 卖给ＮＰＣ
    set("value", 5500); // 从ＮＰＣ购买
}
