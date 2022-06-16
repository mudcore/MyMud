inherit STD_KNIFE;

void create()
{
    ::create();
    set_name("罗马短剑", ({"gladius", "knife"}));
    set("long", "来自异域的短剑，据说刺杀过君王。");
    add("equip_info", ([
        "lv" : 50, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 102,
        "critical" : 0.05,
    ]) );
    set("base_value", 450); // 卖给ＮＰＣ
    set("value", 45000); // 从ＮＰＣ购买
}
