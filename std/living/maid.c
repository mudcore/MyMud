/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: maid.c
Description: 旅馆女仆标准继承对象 STD_MAID
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_NPC;

protected varargs void create(string vocation, int lvl)
{
    ::create(vocation, lvl);
    set_name("旅馆女仆", ({"girl"}));
    set("long", HIM "她是一个可爱的小女仆，想住宿可以找她办理（sleep）。" NOR);
}

void init()
{
    object ob;
    add_action("do_sleep", "sleep");
    if (interactive(ob = this_player()))
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

int do_sleep(string arg)
{
    string msg;
    object me = this_player();
    if (me->query("coin") >= 10)
    {
        me->set_all_full();
        me->add("coin", -10);
        me->start_busy(2 + random(3));
        msg = "$ME在旅馆美美的睡了一觉...体力完全恢复了。";
        msg("vision", msg, me);
        return 1;
    }
    return notify_fail("很遗憾，你的金币不够支付住宿的费用了。T_T\n");
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    msg("info", "$YOU笑眯眯的对$ME说到：“欢迎光临，需要住宿("MAG"sleep"HIC")吗？只需 10 个金币，就能彻底恢复旅途的疲惫。”", ob, this_object());
}
