/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: inn.c
Description: 托拉佩塔城的旅馆
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_INN;

private void create()
{
    ::create();
    set("exits", ([
        "out" : __DIR__"city4",
    ]));
    set("objects", ([
        __DIR__"obj/book": 1,
    ]) );
    setup();
}

void revive(object ob)
{
    int hp = ob->query_hp(), max_hp = ob->query_max_hp();
    if(!strcmp(file_name(environment(ob)), "/wizard/farebury/inn")){
        if(hp < max_hp) {
            ob->add_attr("hp", 5 + random(10));
            if (ob->query_hp() > max_hp) ob->set_attr("hp", max_hp);
            tell_object(ob, HIG "安静的呆了会儿，你感觉自己的体力恢复了一些。\n" NOR);
            call_out("revive", 15, ob);
        }
    }
}
