#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("多拉奇", ({"dracky"}));
    set("long", BLU "在夜空自由飞翔的类似蝙蝠的怪物，有种说法称其原本诞生于没有光明的世界。" NOR);
    set_attr("max_hp", 10);
    set_attr("hp", 10);
    set_attr("str", 13);
    set_attr("vit", 9);
    set_attr("agi", 2);
    set("exp", 2);
    set("coin", 3);
    set("drop_item", ([
        ITEM_DIR "medicinal_herb" : 64,
    ]));
    setup();
}
