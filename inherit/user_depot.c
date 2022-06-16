/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_depot.c
Description: 玩家背包功能接口
Author: xuefeng
Version: v1.0
Date: 2019-03-23
History:
*****************************************************************************/
#include <ansi.h>

mapping my_depot;

int store_item(object me, object ob, int amount);

class store
{
    string name, id, file;
    int amount;
}

nosave class store *all = ({});

int list_bag(string arg)
{
    string msg;
    object me = this_player();

    if (!me->query("bag"))
    {
        return notify_fail("你还没有背包呢。\n");
    }

    if (!all || sizeof(all) < 1)
        return notify_fail("你的背包里没有存放任何物品。\n");

    msg = HIW "\n你的背包里存放的物品有：\n编号  物品                                      数量\n"
              "----------------------------------------------------\n" NOR;
    for (int i = 0; i < sizeof(all); i++)
    {
        msg += sprintf("[%2d]  %-36s      %-11d\n", i + 1, all[i]->name + "(" + all[i]->id + ")", all[i]->amount);
        if (all[i]->amount == 0)
            all[i] = 0;
    }
    msg += HIW "----------------------------------------------------\n" NOR;
    all -= ({0});
    tell_object(me, msg);
    return 1;
}

int do_take(string arg)
{
    object me, ob;
    object *obs;
    int n, amount, num;
    string un;

    me = this_player();

    if (!me->query("bag"))
    {
        return notify_fail("你还没有背包呢。\n");
    }

    if (me->is_busy())
        return notify_fail("你正忙着呢。\n");
    if (me->is_fighting())
        return notify_fail("你正在战斗中呢。\n");

    if (!arg || sscanf(arg, "%d %d", n, amount) != 2)
        return notify_fail("格式错误，请用 take 编号 数量 来取回物品。\n");

    if (amount < 1 || amount > 100)
        return notify_fail("每次取物品的数量不得小于 1 同时也不能大于 100 。\n");

    if (n < 1)
        return notify_fail("你要取第几号物品？\n");

    if (!all || sizeof(all) < 1 || n > sizeof(all))
        return notify_fail("你的背包里没有存放这项物品。\n");
    n--;
    if (amount > all[n]->amount)
        amount = all[n]->amount;

    if (!(ob = new (all[n]->file)))
    {
        all[n] = 0;
        all -= ({0});
        tell_object(me, "无法取出该物品，系统自动清除之。\n");
        return 1;
    }

    obs = filter_array(all_inventory(me), (: !$1->query_temp("equipped") :));
    if (sizeof(obs) >= 100 && !ob->can_combine_to(me))
        return notify_fail("你身上的东西实在是太多了，没法再拿东西了。\n");

    un = ob->query("unit");

    if (ob->query_amount())
    {
        all[n]->amount -= amount;
        if (all[n]->amount == 0)
        {
            all[n] = 0;
            all -= ({0});
        }
        ob->set_amount(amount);
        ob->move(me);

        msg("vision", "$ME从背包里取出一" + un + ob->query("name") + "。", me);
        return 1;
    }
    destruct(ob);

    if (amount > 100)
        amount = 100;
    all[n]->amount -= amount;
    num = amount;
    while (num--)
    {
        ob = new (all[n]->file);
        ob->move(me, 1);
    }

    msg("vision", "$ME从背包里取出" + amount + un + ob->query("name") + "。", me);

    if (!wizardp(me) && random(2))
        me->start_busy(3);

    if (all[n]->amount == 0)
    {
        all[n] = 0;
        all -= ({0});
    }
    return 1;
}

int do_store(string arg)
{
    int i, n, amount;
    string item;
    object me, ob1, ob2, *inv;

    me = this_player();

    if (!me->query("bag"))
    {
        return notify_fail("你还没有背包呢。\n");
    }

    if (me->is_busy())
        return notify_fail("你正在忙着呢！\n");
    if (me->is_fighting())
        return notify_fail("你正在战斗中呢。\n");

    if (!arg)
        return notify_fail("你要存放什么东西？\n");
    n = 100;

    if (sizeof(all) >= n)
    {
        return notify_fail("你背包的 " + n + " 个储藏空间全被使用了，请整理一下吧。\n");
    }

    if (arg == "all")
    {
        inv = all_inventory(me);
        inv -= ({this_object()});
        inv -= ({0});
        inv = filter_array(inv, (: !$1->query_temp("equipped") :));
        n = sizeof(inv);
        if (n > 100)
        {
            tell_object(me, "你身上的物品太多了，很容易搞混，你还是一个一个存吧。\n");
            return 1;
        }

        if (n < 1)
        {
            tell_object(me, "你身上没有任何可以保存的物品。\n");
            return 1;
        }

        for (i = 0; i < n; i++)
        {
            do_store(inv[i]->query("id"));
        }
        return 1;
    }
    else if (sscanf(arg, "%d %s", amount, item) == 2)
    {
        if (!objectp(ob1 = present(item, me)))
            return notify_fail("你身上没有这样东西。\n");

        if (amount < 1)
            return notify_fail("存东西的数量至少是一个。\n");

        if (amount > ob1->query_amount())
            return notify_fail("你没有那么多的" + ob1->name() + "。\n");

        if (amount == (int)ob1->query_amount())
        {
            return store_item(me, ob1, amount);
        }
        else
        {
            ob1->set_amount((int)ob1->query_amount() - amount);
            ob2 = new (base_name(ob1));
            ob2->set_amount(amount);
            if (!store_item(me, ob2, amount))
            {
                ob2->move(me);
                return 0;
            }
            return 1;
        }
    }

    if (!objectp(ob1 = present(arg, me)))
        return notify_fail("你身上没有这样东西。\n");

    if (ob1->query_amount())
        return do_store(ob1->query_amount() + " " + arg);

    store_item(me, ob1, 1);
    return 1;
}

int store_item(object me, object ob, int amount)
{
    class store item;
    int i, n;
    string file, name, id, un;

    if (!objectp(ob))
    {
        error("no this object!\n");
        return 0;
    }

    if (file_size(base_name(ob) + ".c") < 0)
        return 0;

    if (ob->is_character() || ob == this_object() || !clonep(ob))
    {
        tell_object(me, "背包不能保存" + ob->query("name") + "\n");
        return 1;
    }

    if (sizeof(all_inventory(ob)))
    {
        tell_object(me, "请你先把" + ob->query("name") + "里面的东西先拿出来。\n");
        return 1;
    }

    if (ob->query_temp("equipped"))
    {
        tell_object(me, ob->name() + "必须先解除装备才能存放。\n");
        return 1;
    }

    name = ob->query("name");
    file = base_name(ob);
    id = ob->query("id");
    un = ob->query("unit");

    n = sizeof(all);
    for (i = 0; i < n; i++)
    {
        if (all[i]->file == file && all[i]->id == id && all[i]->name == name)
        {
            all[i]->amount += amount;
            msg("vision", "$ME把" + amount + un + ob->query("name") + "存到背包里。", me);
            destruct(ob);
            return 1;
        }
    }

    item = new (class store);
    item->file = file;
    item->name = name;
    item->id = id;
    item->amount = amount;
    all += ({item});
    msg("vision", "$ME把" + amount + un + ob->query("name") + "存到背包里。", me);
    destruct(ob);
    return 1;
}

// 恢复背包物品
void restore_depot()
{
    int i, n;
    class store item;
    mapping data = my_depot;

    if (!mapp(data) || sizeof(data) < 1)
        return 0;

    n = sizeof(data);
    for (i = 0; i < n; i++)
    {
        item = new (class store);
        item->name = data["item" + i]["name"];
        item->id = data["item" + i]["id"];
        item->file = data["item" + i]["file"];
        item->amount = data["item" + i]["amount"];
        all += ({item});
    }
}

// 保存背包物品
void save_depot()
{
    mapping data, list;
    int i, n;
    data = ([]);

    if (sizeof(all) > 0)
    {
        n = sizeof(all);
        for (i = 0; i < n; i++)
        {
            list = ([]);
            list["name"] = all[i]->name;
            list["id"] = all[i]->id;
            list["file"] = all[i]->file;
            list["amount"] = all[i]->amount;
            data += (["item" + i:list]);
        }
    }
    my_depot = data;
}
