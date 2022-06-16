// 解毒草
#include <ansi.h>
inherit STD_MEDICINE;

void create()
{
    ::create();
    set_name(HIG "特等解毒草" NOR, ({"special antidotal herb", "medicine", "herb", "7"}));
    set("long", "解除中毒状态并回复90~120HP。");
    set("base_value", 40);
    set("value", 120);
    set("unit", "株");
    set("effect", ([
        "heal":({"hp", 90, 30}), // 恢复：类型，基础值，波动
        "cure":({"poison"}),     // 治疗,可治疗的负面状态，包括死亡、中毒等
    ]));
}
