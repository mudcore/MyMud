/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: item.c
Description: 物品功能公共接口
Author: xuefeng
Version: v1.0
Date: 2019-03-14
History:
*****************************************************************************/
inherit _CLEAN_UP;
inherit _DBASE;
inherit _MOVE;
inherit _NAME;

nosave int amount;

int is_item() { return 1; }

// allows an object to do self-maintenance
void reset()
{
    /*
    write_file(LOG_DIR + "reset", "[ITEM]->reset():" +
        sprintf("%-50s%s", file_name(this_object()), ctime(time()) + "\n"));
    */
}

int query_amount() { return amount; }

void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
    if (v < 1)
    {
        amount = 0;
        call_out("destruct_me", 0);
    }
    else
    {
        amount = v;
        set_temp("amount", v);
    }
}

void add_amount(int v) { set_amount(amount + v); }

varargs int move(mixed dest, int silent)
{
    object env, *inv;
    int i, total = 1;
    string file;

    if (::move(dest))
    {
        env = environment();
        if (objectp(env) && !query_temp("equip"))
        {
            file = base_name(this_object());
            inv = filter_array(all_inventory(env), (: !$1->query_temp("equipped") :));

            if (query_temp("amount"))
                total = (int)query_temp("amount");

            for (i = 0; i < sizeof(inv); i++)
            {
                if (inv[i] == this_object())
                    continue;
                if (base_name(inv[i]) == file)
                {
                    total += (int)inv[i]->query_temp("amount");
                    destruct(inv[i]);
                }
            }
            set_amount(total);
        }
        return 1;
    }
}

// does I can combine to an item in the object env ?
int can_combine_to(object env)
{
    object item;
    string file;

    file = base_name(this_object());
    foreach (item in all_inventory(env))
        if (base_name(item) == file)
            return 1;

    return 0;
}

// 物品使用效果
int do_effect(object me)
{
    msg("vision", "$ME使用了" + this_object()->name() + "，然而什么事都没发生！", me);
    return 1;
}

void setup()
{
}
