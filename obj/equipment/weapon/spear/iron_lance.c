inherit STD_SPEAR;

void create()
{
    ::create();
    set_name("铁枪", ({"iron lance", "spear", "lance"}));
    set("long", "精铁打造的长枪，是王国士兵的常用装备。");
    add("equip_info", ([
        "lv" : 10, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 17,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 550); // 从ＮＰＣ购买
}
