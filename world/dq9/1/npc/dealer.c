#include <ansi.h>
inherit STD_DEALER;

protected void create()
{
    ::create("thief", 15);
    set_name("杂货商", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种千奇百怪但又实用的杂货。" NOR);
    set("vendor_goods", ({
        ITEM_DIR "medicinal_herb",
        ITEM_DIR "holy_water",
        ITEM_DIR "chimaera_wing",
        ARMOUR_DIR "arm/cotton_gloves",
        ARMOUR_DIR "body/plain_clothes",
        ARMOUR_DIR "body/wayfarer_clothes",
        ARMOUR_DIR "body/leather_armour",
        ARMOUR_DIR "foot/sandals",
        ARMOUR_DIR "foot/leather_shoes",
        ARMOUR_DIR "head/bandana",
        ARMOUR_DIR "leg/boxer_shorts",
        ARMOUR_DIR "leg/cotton_trousers",
        ARMOUR_DIR "shield/pot_lid",
        ARMOUR_DIR "shield/leather_shield",
        WEAPON_DIR "sword/copper_sword",
        WEAPON_DIR "sword/soldier_sword",
        WEAPON_DIR "wand/oak_staff",
        WEAPON_DIR "whip/leather_whip",
        WEAPON_DIR "fan/feather_fan",
    }));
}
