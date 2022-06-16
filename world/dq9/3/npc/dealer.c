#include <ansi.h>
inherit STD_DEALER;

protected void create()
{
    ::create();
    set_name("杂货商", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种千奇百怪但又实用的杂货。" NOR);
    set("vendor_goods", ({
        ITEM_DIR "medicinal_herb",
        ITEM_DIR "antidotal_herb",
        ITEM_DIR "holy_water",
        ITEM_DIR "magic_water",
        ITEM_DIR "chimaera_wing",
    }));
}
