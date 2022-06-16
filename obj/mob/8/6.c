#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("双椒串", ({"capsichum"}));
    set("long", GRN "青椒形状的怪物，因为两只一起才能独当一面，所以为了不走丢，将身体串在一起。" NOR);
    set_attr("max_hp", 15);
    set_attr("max_mp", 4);
    set_attr("hp", 15);
    set_attr("mp", 4);
    set_attr("str", 12);
    set_attr("vit", 12);
    set_attr("agi", 4);
    set("exp", 3);
    set("coin", 3);
    set("drop_item", ([
        ARMOUR_DIR "body/plain_clothes" : 16,
        ARMOUR_DIR "body/wayfarer_clothes" : 64,
    ]));
    setup();
}
