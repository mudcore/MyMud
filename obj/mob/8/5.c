#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("角笛吹奏者", ({"satyr"}));
    set("long", CYN "长着角的人形怪物，两只耳朵上每年都会重新生出一对巨大对角，手中所持的角笛就是用脱落的角制成的。" NOR);
    set_attr("max_hp", 13);
    set_attr("hp", 13);
    set_attr("str", 15);
    set_attr("vit", 10);
    set_attr("agi", 8);
    set("exp", 3);
    set("coin", 4);
    set("drop_item", ([
        ITEM_DIR "medicinal_herb" : 16,
        WEAPON_DIR "sword/copper_sword" : 256,
    ]));
    setup();
}
