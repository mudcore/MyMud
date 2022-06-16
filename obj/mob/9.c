inherit STD_MOB;

void drop_item(int index);
void set_action(int index);

varargs void create(int index)
{
    ::create(index);
    drop_item(index);
    set_action(index);
}

void drop_item(int index)
{
    switch (index)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        set("drop_item", ([
            ITEM_DIR "medicinal_herb":256,
        ]));
        break;
    case 7:
    case 8:
    case 9:
        set("drop_item", ([
            ITEM_DIR "rose_root":256,
            ARMOUR_DIR "body/plain_clothes":512,
            ARMOUR_DIR "body/wayfarer_clothes":1024,
        ]));
        break;
    case 10:
    case 12:
    case 19:
    case 30:
        set("drop_item", ([
            ITEM_DIR "magic_water":128,
            ITEM_DIR "sage_elixir":1024,
        ]));
        break;
    case 17:
        set("drop_item", ([
            WEAPON_DIR "sword/copper_sword":128,
        ]));
        break;
    case 18:
    case 20:
    case 21:
    case 22:
    case 23:
        set("drop_item", ([
            ARMOUR_DIR "shield/silver_platter":128,
        ]));
        break;
    case 59:
    case 76:
    case 210:
        set("drop_item", ([
            ITEM_DIR "chimaera_wing":512,
        ]));
    default:
        set("drop_item", ([
            ITEM_DIR "medicinal_herb":128,
            ITEM_DIR "strong_medicine":256,
            ITEM_DIR "strong_antidote":512,
            ITEM_DIR "rose_root":512,
            ITEM_DIR "special_medicine":1024,
            ITEM_DIR "special_antidote":1024,
        ]));
        break;
    }
}

void set_action(int index)
{
    switch (index)
    {
    case 10:
    case 12:
    case 19:
    case 30:
    case 40:
    case 43:
    case 53:
    case 54:
    case 68:
    case 102:
    case 120:
        set("action", ([
            "spell":({"fire"}),
            "chance":3,
        ]));
        break;
    case 25:
    case 74:
    case 101:
    case 218:
    case 264:
        set("action", ([
            "poison":1,
            "chance":3,
        ]));
        break;
    case 29:
    case 83:
    case 131:
        set("action", ([
            "spell":({"heal"}),
            "chance":5,
        ]));
        break;
    case 46:
    case 89:
    case 153:
    case 214:
    case 229:
        set("action", ([
            "flee": 1,
            "chance":2,
        ]));
        break;
    // BOSS 技能
    case 257:
        set("action", ([
            "spell":({"heal", "dark"}),
            "chance":5,
        ]));
        break;
    default:
        break;
    }
}
