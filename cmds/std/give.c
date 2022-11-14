/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: give.c
Description: 物品交换指令
Author: xuefeng
Version: v1.0
Date: 2019-03-18
History:
*****************************************************************************/
#include <ansi.h>
inherit _CLEAN_UP;

int do_give(object me, object obj, object who);

int main(object me, string arg)
{
    string target, item;
    object obj, obj2, who;
    int coin, amount = 1;

    if (! arg) return notify_fail("你要给谁什么东西？\n");

    if (sscanf(arg, "%s to %s", item, target) == 2 ||
        sscanf(arg, "%s %s", target, item) == 2 );
    else return notify_fail("你要给谁什么东西？\n");

    if (! objectp(who = present(target, environment(me))))
    {
        return notify_fail("这里没有这个人。\n");
    }

    if (sscanf(item, "%d %s", amount, item) == 2)
    {
        if (amount < 1)
            return notify_fail("成功啦！兴奋吧？\n");

        // 交易金币
        if (!strcmp(item, "coin"))
        {
            coin = me->query("coin");
            if (amount > coin)
            {
                return notify_fail("你没有那么多的金币。\n");
            } else {
                me->add("coin", -amount);
                who->add("coin", amount);
                msg("warning","$ME拿出" + amount + "枚金币给$YOU。", me, who);
            }
            return 1;
        }
    }

    if (! objectp(obj = present(item, me)))
        return notify_fail("你身上没有这样东西。\n");

    if (amount > obj->query_amount() )
        return notify_fail("你没有那么多的" + obj->name() + "。\n");

    if (obj->query("no_drop"))
        return notify_fail("这样东西不能随便给人。\n");

    if (living(obj))
    {
        return notify_fail("天哪！你是魔物吗？怎么做这样的事？\n");
    }

    if (me == who)
        return notify_fail("你自己给自己东西干吗？\n");

    if (! living(who))
        return notify_fail("你还是得等人家复活后再说吧。\n");

    if (! userp(who))
    {
        // todo 非玩家角色接受物品处理
    }

    if (amount == (int)obj->query_amount())
    {
        do_give(me, obj, who);
        return 1;
    } else
    {
        obj->set_amount((int)obj->query_amount() - amount);
        obj2 = new(base_name(obj));
        obj2->set_amount(amount);
        if (do_give(me, obj2, who))
            return 1;
        else
        if (obj2)
        {
            obj->set_amount((int)obj->query_amount() + amount);
            destruct(obj2);
            return 1;
        }
    }
    return 1;
}

int do_give(object me, object obj, object who)
{
    if(obj->query_temp("equipped")&& obj->query_amount() == 1)
    {
        tell_object(me, obj->name() + "必须解除装备才能给别人。\n");
        return 0;
    }

    msg("info","$ME拿出" + obj->short() + "给$YOU。", me, who);

    if (! userp(who))
    {
        destruct(obj);
        return 1;
    }

    if (! obj->move(who))
    {
        msg("warning","然而$YOU没能拿住$ME的" + obj->name() + "。", me, who);
        return 0;
    }

    return 1;
}

int help()
{
    write(@HELP
指令格式：give <物品名称> to <某人>
          give <数量> <物品名称> to <某人>

这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
这个指令也可以给别人金币，要求格式必须是 give <数量> coin to <某人>

HELP);
    return 1;
}
