#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "医疗草" NOR, ({"rose root", "medicine", "herb", "4"}));
    set("long", "我方单体HP60~80恢复。");
    set("base_value", 35);
    set("value", 80);
    set("effect", ([
        "heal":({"hp", 60, 20}), // 恢复：类型，基础值，波动值
    ]));
}
