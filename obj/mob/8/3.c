#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("厚唇蛞蝓", ({"lips"}));
    set("long", GRN "以巨大嘴唇为特征的类同蛞蝓的怪物，据说同伴之间会用热吻来打招呼。" NOR);
    set_attr("max_hp", 11);
    set_attr("hp", 11);
    set_attr("str", 11);
    set_attr("vit", 7);
    set_attr("agi", 5);
    set("exp", 2);
    set("coin", 3);
    set("drop_item", ([
        ITEM_DIR "medicinal_herb" : 16,
    ]));
    setup();
}
