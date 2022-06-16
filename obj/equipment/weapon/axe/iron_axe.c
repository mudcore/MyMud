inherit STD_AXE;

void create()
{
    ::create();
    set_name("铁斧", ({"iron axe", "axe"}));
    set("long", "用精铁制成的锋利斧头。");
    add("equip_info", ([
        "lv" : 30, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 30,
    ]) );
    set("base_value", 250); // 卖给ＮＰＣ
    set("value", 2500); // 从ＮＰＣ购买
}
