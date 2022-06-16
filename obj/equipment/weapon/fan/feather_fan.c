/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: feather_fan.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_FAN;

void create()
{
    ::create();
    set_name("羽扇", ({"feather fan", "fan"}));
    set("long", "用孔雀的羽毛作为材料制成的华丽的扇子。");
    set("equip_effect", ([
        "damage" : 9,
    ]) );
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 150); // 从ＮＰＣ购买
}
