#include <ansi.h>
inherit STD_DEALER;

protected void create()
{
    ::create();
    set_name("武器商", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种武器装备。" NOR);
    set("vendor_goods", ({
        WEAPON_DIR "axe/iron_axe",
        WEAPON_DIR "boomerang/boomerang",
        WEAPON_DIR "bow/short_bow",
        WEAPON_DIR "claw/iron_claws",
        WEAPON_DIR "claw/stone_claws",
        WEAPON_DIR "fan/feather_fan",
        WEAPON_DIR "hammer/war_hammer",
        WEAPON_DIR "knife/bronze_knife",
        WEAPON_DIR "knife/divine_dagger",
        WEAPON_DIR "knife/gladius",
        WEAPON_DIR "knife/paring_knife",
        WEAPON_DIR "spear/bamboo_lance",
        WEAPON_DIR "spear/demon_spear",
        WEAPON_DIR "spear/iron_lance",
        WEAPON_DIR "staff/carrying_pole",
        WEAPON_DIR "staff/dragon_rod",
        WEAPON_DIR "staff/laundry_pole",
        WEAPON_DIR "sword/falcon_blade",
        WEAPON_DIR "sword/iron_sword",
        WEAPON_DIR "sword/rapier",
        WEAPON_DIR "sword/warrior_sword",
        WEAPON_DIR "wand/wizard_staff",
        WEAPON_DIR "wand/sage_staff",
        WEAPON_DIR "whip/queen_whip",
        WEAPON_DIR "whip/thorn_whip",
    }));
}
