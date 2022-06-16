#include <ansi.h>

inherit STD_MOB;

private void create()
{
    ::create();
    set_name("史莱姆", ({"slime"}));
    set("long", CYN "一只天蓝色果冻状的小魔物，遍布在世界各地，据说其中还有会讲人类语言的家伙。" NOR);
    set("drop_item", ([
        ITEM_DIR "medicinal_herb" : 32,
    ]));
    setup();
}
