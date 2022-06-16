/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: kill.c
Description: kill指令
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>

int main(object me, string arg)
{
    object ob;
    mixed info;

    if (environment(me)->query("no_fight"))
        return notify_fail("这里禁止战斗。\n");

    if (!arg || !objectp(ob = present(arg, environment(me))))
        return notify_fail("你想攻击谁？\n");

    if (!ob->is_character())
        return notify_fail("你很中二的对着" + ob->name() + "喊道：有本事和我PK！\n");

    if (info = ob->query("no_fight"))
        return notify_fail(stringp(info) ? info : CYN "在你出手前想起了神灵的教诲，决定放弃这么做。\n" NOR);

    if (ob->is_fighting(me))
        return notify_fail(HIY "加油！加油！加油！\n" NOR);

    if (userp(ob) && !interactive(ob))
        return notify_fail(ob->name() + "已经无法战斗了。\n");

    if (userp(ob) && sizeof(ob->query_enemy())) {
        return notify_fail(ob->name() + "正在拼命中，你这样做不怕遭报应？\n");
    }

    if (ob == me) return notify_fail("你不能攻击自己。\n");

    if (! me->is_fighting(ob) && me->query_hp() < me->query_max_hp() * 3 / 10)
        return notify_fail("你自己都快死了还想杀别人？\n");

    msg("vision", "$ME大喝一声，对$YOU发起了攻击。", me, ob);
    me->kill_ob(ob);

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : kill [id]

这个指令可以让你主动攻击其他玩家或NPC。

HELP );
    return 1;
}
