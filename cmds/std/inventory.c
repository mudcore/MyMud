//inventory.c

#include <ansi.h>

string desc_of_objects(object *obs);

int main(object me, string arg)
{
    object *inv, ob;
    string str;

    if (wizardp(me) && arg)
    {
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) ob = present(arg, environment(me));
    }

    if (!ob) ob = me;

    inv = all_inventory(ob);
    if (! sizeof(inv))
    {
        write((ob == me) ? "目前你身上没有任何东西。\n"
                         : ob->name() + "身上没有携带任何东西。\n");
        return 1;
    }
    str = sprintf("%s身上带著下列这些东西：\n", (ob == me)? "你" : ob->name());
    str += desc_of_objects(inv);

    write(str);
    return 1;
}

string desc_of_objects(object *obs)
{
    int i;
    string  str;
    mapping list, unit, equipped;
    string  short_name;
    string  *ob;

    if (obs && sizeof(obs) > 0)
    {
        str = "";
        list = ([]);
        unit = ([]);
        equipped = ([]);
        for (i = 0; i < sizeof(obs); i++)
        {
            if (obs[i]->query_temp("equipped")) {
                short_name = HIC "□" NOR + obs[i]->short();
                equipped[short_name] = 1;
            } else
                short_name = obs[i]->short();
            list[short_name] += obs[i]->query_temp("amount");
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(ob); i++)
        {
            if (!equipped[ob[i]])
                str += "  ";
            if (list[ob[i]]>1)
                str += list[ob[i]] + unit[ob[i]] + ob[i] + "\n";
            else
                str += ob[i] + "\n";
        }
        return str;
    }

    return "";
}

int help(object me)
{
    write(@HELP
指令格式 : i

这个指令可以让你查看自己携带的物品。

HELP );
    return 1;
}
