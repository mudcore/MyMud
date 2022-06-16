// 解毒草
#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "解毒草" NOR, ({"antidotal herb", "medicine", "herb", "5"}));
    set("long", "解除中毒状态。");
    set("base_value", 5);
    set("value", 15);
    set("unit", "株");
    set("effect", ([
        "cure":({"poison"}),             // 治疗,可治疗的负面状态，包括死亡、中毒等
    ]));
}
