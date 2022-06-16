#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("条纹猫", ({"candy cat", "candy", "cat"}));
    set("long", YEL "性格悠闲的怪物，出生时身上只有一根条纹，之后会随着年龄的增长，每年增加一根。" NOR);
    set_attr("max_hp", 10);
    set_attr("hp", 10);
    set_attr("str", 9);
    set_attr("vit", 6);
    set_attr("agi", 4);
    set("exp", 2);
    set("coin", 2);
    set("drop_item", ([
        ITEM_DIR "medicinal_herb" : 32,
    ]));
    setup();
}
