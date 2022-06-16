inherit STD_KNIFE;

void create()
{
    ::create();
    set_name("青铜小刀", ({"bronze knife", "knife"}));
    set("long", "青铜制造的小刀，轻巧古朴，既能做饰品也能做武器。");
    add("equip_info", ([
        "lv" : 5, // 级别要求
    ]) );
    set("equip_effect", ([
        "damage" : 10,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 350); // 从ＮＰＣ购买
}
