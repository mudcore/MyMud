inherit STD_STAFF;

void create()
{
    ::create();
    set_name("扁担", ({"carrying pole", "pole", "staff"}));
    set("long", "这是挑东西用的扁担，结实而有韧性。");
    set("equip_effect", ([
        "damage" : 15,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 700); // 从ＮＰＣ购买
}
