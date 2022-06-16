inherit STD_CLAW;

void create()
{
    ::create();
    set_name("铁爪", ({"iron claws", "claw", "claws"}));
    set("long", "精铁打造的爪套，尖端锋利无比。");
    add("equip_info", ([
        "lv" : 10, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 17,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 750); // 从ＮＰＣ购买
}
