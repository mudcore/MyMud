#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "上等草药" NOR, ({"strong medicinal herb", "medicine", "herb", "2"}));
    set("long", "我方单体HP40~60恢复。");
    set("base_value", 18);
    set("value", 40);
    set("effect", ([
        "heal":({"hp", 40, 20}), // 恢复：类型，基础值，波动值
    ]));
}
