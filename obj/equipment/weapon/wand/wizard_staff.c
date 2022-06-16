inherit STD_WAND;

void create()
{
    ::create();
    set_name("魔道士之杖", ({"wizard staff", "staff", "wand"}));
    set("long", "魔道士常用的普通魔杖。");
    set("equip_effect", ([
        "damage" : 7,
        "mp_rate" : 0.015, // MP吸收率
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 850); // 从ＮＰＣ购买
}
