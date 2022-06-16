#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("独角兔", ({"bunicorn"}));
    set("long", WHT "因为心生恶念而长出了角的兔子，一旦发现猎物就会全速冲过去。" NOR);
    set_attr("max_hp", 16);
    set_attr("hp", 16);
    set_attr("str", 19);
    set_attr("vit", 14);
    set_attr("agi", 5);
    set("exp", 5);
    set("coin", 5);
    set("drop_item", ([
        ACCESSORY_DIR "bunny_tail" : 128,
        ARMOUR_DIR "head/leather_hat" : 64,
    ]));
    setup();
}
