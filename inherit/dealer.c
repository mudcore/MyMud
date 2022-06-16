// dealer.c 商人

#include <ansi.h>
#include <dbase.h>
#include <name.h>

#define LOOK_CMD "/cmds/std/look"

string is_vendor_good(string arg)
{
    mixed goods;
    int i;

    goods = query("vendor_goods");
    if (mapp(goods))
        goods = keys(goods);

    if (arrayp(goods))
        for (i = 0; i < sizeof(goods); i++)
        {
            // debug(goods[i]);
            if (goods[i]->id(arg)) return goods[i];
        }
    return "";
}

int do_value(string arg)
{
    // todo
}

int do_sell(string arg)
{
    object me;
    object ob;
    string my_id;
    int amount;
    int value;
    int max_count;
    mixed ns;

    if (! arg)
        return notify_fail("你要卖什么？\n");

    if (sscanf(arg, "%s to %s", arg, my_id) == 2 && ! id(my_id))
        return 0;

    if (sscanf(arg, "%d %s", amount, arg) != 2)
        // not indicate the amount of the goods
        amount = 1;

    me = this_player();
    if (! (ob = present(arg, me)))
    {
        write("你身上没有这种东西啊！\n");
        return 1;
    }

    if (amount < 1)
    {
        write("亏你想的出来，有这样卖东西的吗？\n");
        return 1;
    }

    max_count = ob->query_amount();
    if (! max_count)
    {
        max_count = 1;
    }

    if (amount > max_count)
    {
        write("你身上没有这么多" + ob->name() + "。\n");
        return 1;
    }

    if (ob->is_character())
    {
        write(CYN + name() + "说道：“天啦，你是魔王派来的吗？怎么做这种事！”\n" NOR);
        return 1;
    }

    if (ob->query_temp("equipped"))
    {
        write(CYN + name() + "说道：“这个你正装备着呀，如果要卖给我请先脱下来吧。”\n" NOR);
        return 1;
    }

    if (ns = ob->query("no_sell"))
    {
        if (stringp(ns))
        {
            command("say " + ns);
            return 1;
        }
        write(CYN + name() + "摇摇头，说：“这种东西我不识货，不敢要。”\n" NOR);
        return 1;
    }


    value = ob->query("base_value") * amount;

    if (value < 1)
    {
        value = 0;
        write(CYN + name() + "说道：“" + ob->query("name") +
              CYN "不值钱，我帮你回收处理了哦！”\n" NOR);
    }

    write_file(LOG_DIR + "dealer", "[DEALER]->do_sell():" +
        sprintf("%-15s%-15s%-10d%s", me->short(), arg , value, ctime(time()) + "\n"));

    ob->add_amount(-amount);

    msg("warning", "$ME卖掉了" + ob->query("name") + "给$YOU。",
        this_player(), this_object());

    this_player()->add("coin", value);

    return 1;
}

int do_list(string arg)
{
    mixed  goods;
    string *gks;
    string msg;
    int i;
    object gob;
    mapping list = ([]);
    mapping price = ([]);
    mapping unit = ([]);
    string  short_name;
    string  *dk;

    if (arg && ! id(arg))
        return 0; // Don't notify_fail
    goods = query("vendor_goods");
    if (arrayp(goods) || mapp(goods))
    {
        gks = mapp(goods) ? keys(goods) : goods;
        for (i = 0; i < sizeof(gks); i++)
        {
            if (! objectp(find_object(gks[i])) && ! objectp(new(gks[i])))
            {
                log_file("goods", sprintf("No found vendor good:%s\n", gks[i]));
                continue;
            }
            gob = find_object(gks[i]);
            short_name = gob->short();
            list[base_name(gob)] = gob->short();
            price[base_name(gob)] = gob->query("value");
            unit[base_name(gob)] = gob->query("unit");
        }
        msg = this_object()->name() + "目前出售以下物品：\n";
        dk = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(dk); i++)
        {
            int p;
            p = price[dk[i]];
            //msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
            msg += sprintf("%-40s %d\n", list[dk[i]], price[dk[i]]);
        }
    } else {
        msg = this_object()->name() + "目前没有出售任何物品。\n";
    }

    write(msg);
    return 1;
}

int do_buy(string arg)
{
    mapping goods;
    int     amount;
    int     value;
    string  ob_file;
    object  ob;
    string  my_id;
    string  start_room;
    object  room;
    object  me;
    mapping room_obmap;

    if (! arg)
        return notify_fail("你想买什么？\n");

    if (sscanf(arg, "%s from %s", arg, my_id) == 2 && ! id(my_id))
        return 0;

    if (query_temp("busy"))
    {
        write(CYN + name() + CYN "说道：现在正忙着，慢慢来哦。\n" NOR);
        return 1;
    }

    me = this_player();

    if (stringp(start_room = query("home")) &&
        (room = find_object(start_room)) != environment())
    {
        // I am not in start room.
        msg("vision", CYN "$ME" CYN "说道：咦？我怎么跑到这儿"
            "来了？\n" NOR "$ME头也不回的急急忙忙溜"
            "走了。" NOR, this_object());

        if (! objectp(room) ||
            ! mapp(room_obmap = room->query_temp("objects")))
        {
            destruct(this_object());
        } else
            this_object()->move(room);
        return 1;
    }

    if (sizeof(filter_array(all_inventory(me), (: ! $1->query_temp("equipped") :))) >= 100)
    {
        write("你身上的东西太多了，先处理一下再买东西吧。\n");
        return 1;
    }

    if (sscanf(arg, "%d %s", amount, arg) != 2)
    {
        amount = 1;
    } else {
        amount = abs(amount);
    }

    if (amount > 999)
    {
        write(CYN + name() + "说道：一次最多只能买 999 件。\n" NOR);
        return 1;
    }

    if (!(ob_file = is_vendor_good(arg)) || !objectp(ob = new(ob_file)))
    {
        write(this_object()->name() +"这里没有这样物品出售。\n");
        return 1;
    }

    if (amount > 1 && ob->is_equipment())
    {
        write(ob->name() + "只能一" + ob->query("unit") +
              "一" + ob->query("unit") + "的买。\n");
        return 1;
    }

    if (ob->query_amount())
    {
        if (amount > ob->query_amount())
        {
            write("人家那里可没有这么多的" + ob->name() + "！\n");
            return 1;
        }
    }

    if (mapp(goods = query("vendor_goods")) && (int)goods[base_name(ob)] > 0)
    {
        goods[base_name(ob)] -= amount;
    }

    ob->set_amount(amount);
    value = ob->query("value");
    value *= amount;

    if (me->query("coin") < value) {
        write("你的钱不够买啦！\n");
        return 1;
    }
    write_file(LOG_DIR + "dealer", "[DEALER]->do_buy():" +
        sprintf("%-15s%-15s%-10d%s", me->short(), arg , value, ctime(time()) + "\n"));

    set_temp("busy", 1);
    msg("vision", "$ME从$YOU那里买下了" + ob->short() + "。",
         me, this_object());

    me->add("coin", -value);
    ob->move(me);

    remove_call_out("enough_rest");
    call_out("enough_rest", 1 + random(3));

    return 1;
}

// 显示商品属性资料
int do_show(string arg)
{
    string  ob_file;
    object  ob;
    string  my_id;
    object  me;

    if (! arg)
        return notify_fail("你想看什么商品？\n");

    if (sscanf(arg, "%s from %s", arg, my_id) == 2 && ! id(my_id))
        return 0;

    me = this_player();

    if (!(ob_file = is_vendor_good(arg)) || !objectp(ob = new(ob_file)))
    {
        write(this_object()->name() +"这里没有这样物品出售。\n");
        return 1;
    }

    return LOOK_CMD->look_item(me, ob);
}

void destruct_it(object ob)
{
    if (! ob || environment(ob))
        return;
    destruct(ob);
}

void enough_rest()
{
    delete_temp("busy");
}

void reset()
{
    int i;
    object *obs;

    obs = all_inventory();
    for (i = 0; i < sizeof(obs); i++)
        if (i >= 10)
            destruct(obs[i]);
}

void create()
{
    // debug_message("LINE:" + __LINE__);
}
