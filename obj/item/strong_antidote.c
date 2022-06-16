// 解毒草
#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "上等解毒草" NOR, ({"strong antidotal herb", "medicine", "herb", "6"}));
    set("long", "解除中毒状态并回复40~60HP。");
    set("base_value", 25);
    set("value", 60);
    set("unit", "株");
    set("effect", ([
        "heal":({"hp", 40, 20}), // 恢复：类型，基础值，波动
        "cure":({"poison"}),     // 治疗,可治疗的负面状态，包括死亡、中毒等
    ]));
}
