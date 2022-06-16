/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: divine.c
Description: 教堂神官标准继承对象 STD_DIVINE
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_NPC;

protected varargs void create(string vocation, int lvl)
{
    if (!stringp(vocation))
    {
        vocation = "priest";
    }
    if (!lvl)
    {
        lvl = 20;
    }

    ::create(vocation, lvl);
    set_name("神官", ({"divine"}));
    set("long", HIY "一个神官，看起来年龄不大，但目光深邃，好像可以看透一切，如果需要祈祷(pray)可以找他。" NOR);
    set("gender", "男性");
}

void init()
{
    object ob;
    if (interactive(ob = this_player()))
    {
        add_action("do_pray", "pray");
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

int do_pray(string arg){
    string msg;
    object me = this_player();
    int exp = LEVEL_D->exp(me);
    msg = "$YOU对$ME说到：“" + me->query("name") + "啊，你还差 " + exp + " 点经验就能升级到下一级了。”";
    msg("vision", msg, me, this_object());
    if (me->query("lv") > 9)
    {
        // 设置重生点
        me->set("reborn_room", base_name(environment(me)));
    }
    // 最后存档时间
    me->set("last_saved_at", time());
    // 保存背包数据
    me->save_depot();
    // 保存物品数据
    me->save_inventory();
    // 保存所有数据
    me->save();
    return 1;
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment()) return;
    msg("info", "$YOU对$ME说到：“受神指引但迷途的冒险者啊，欢迎来到教会，有什么事吗？”", ob, this_object());
}
