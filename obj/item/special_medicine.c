#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "特等草药" NOR, ({"special medicinal herb", "medicine", "herb", "3"}));
    set("long", "我方单体HP90~120恢复。");
    set("base_value", 50);
    set("value", 120);
    set("effect", ([
        "heal":({"hp", 90, 30}), // 恢复：类型，基础值，波动值
    ]));
}
