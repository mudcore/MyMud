/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: room.c
Description: NPC标准继承对象 STD_NPC
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit _NPC;

varargs void create(string vocation, int lvl)
{
    mixed level_info;
    if (!stringp(vocation))
    {
        vocation = "common";
    }
    if (lvl < 1)
    {
        lvl = 1 + random(99);
    }
    if (lvl > 99)
    {
        lvl = 99;
    }

    level_info = LEVEL_D->level_info(vocation);

    set_name("小女孩", ({"girl"}));
    set("long", "这是一个小女孩，一直梦想长大后成为托拉佩塔城公主的侍女。");
    set("gender", "女性");
    set("vocation", vocation);
    set("lv", lvl);
    set_attr("str", level_info[lvl][0]);
    set_attr("agi", level_info[lvl][1]);
    set_attr("vit", level_info[lvl][2]);
    set_attr("luk", level_info[lvl][3]);
    set_attr("charm", level_info[lvl][4]);
    set_attr("mend", level_info[lvl][5]);
    set_attr("int", level_info[lvl][6]);
    set_attr("max_hp", level_info[lvl][7]);
    set_attr("max_mp", level_info[lvl][8]);
    // set("exp", 10);
    // set("coin", 2);
    set("no_get", "你想绑架啊？\n");
    set("no_fight", 1);
    set("action", ([        // 随机行为
        "spell" : ({ }),    // 可用咒文列表
        "skill" : ({ }),    // 可用特技列表
        "msg" : ({ }),      // 随机说话内容
        "chance" : 0,       // 行为机率，数值越大机率越小
    ]));
    setup();
}
