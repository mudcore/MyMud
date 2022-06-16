#include <ansi.h>
inherit STD_DEALER;

protected void create()
{
    ::create();
    set_name("防具商", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种防具。" NOR);
    set("vendor_goods", ({
        ARMOUR_DIR "arm/cotton_gloves",
        ARMOUR_DIR "body/wayfarer_clothes",
        ARMOUR_DIR "body/leather_armour",
        ARMOUR_DIR "body/leather_dress",
        ARMOUR_DIR "foot/sandals",
        ARMOUR_DIR "foot/leather_shoes",
        ARMOUR_DIR "head/leather_hat",
        ARMOUR_DIR "leg/boxer_shorts",
        ARMOUR_DIR "leg/cotton_trousers",
        ARMOUR_DIR "shield/scale_shield",
        ARMOUR_DIR "shield/leather_shield",
    }));
}
