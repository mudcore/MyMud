/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: Boxer_shorts.c
Description:
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit STD_TROUSER;

void create()
{
    ::create();
    set_name("大裤衩", ({"boxer shorts", "shorts"}));
    set("long", "弥漫着男人哀愁的男性用下装。");
    set("equip_info", ([
        "type" : "trouser", // 装备类型
        "vocation" : ({}), // 职业限制
        "gender" : 1, // 性别要求：0 通用、1 男性、2 女性
        "lv" : 1, // 级别要求
    ]) );
    set("equip_effect", ([
        "defense" : 2,
        "agi" : 2,
    ]) );
    set("base_value", 20); // 卖给ＮＰＣ
    set("value", 100); // 从ＮＰＣ购买
}
