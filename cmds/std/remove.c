// remove.c

#include <ansi.h>
inherit _CLEAN_UP;

int do_remove(object me, object ob);

int main(object me, string arg)
{
    object ob, *inv;
    int i;
    int count;

    if (! arg) return notify_fail("你要脱掉什么？\n");

    if (arg == "all")
    {
        inv = all_inventory(me);
        for (count = 0, i = 0; i < sizeof(inv); i++)
            count += do_remove(me, inv[i]);
        if (count)
            write("你脱完了。\n");
        else
            write("你什么都没有脱下来。\n");
        return 1;
    }

    if (! objectp(ob = present(arg, me)))
        return notify_fail("你身上没有这样东西。\n");

    if (!ob->query_temp("equipped"))
    {
        inv = all_inventory(me);
        for (count = 0, i = 0; i < sizeof(inv); i++)
        {
            if( !inv[i]->id(arg) || !inv[i]->query_temp("equipped"))
                continue;

            ob = inv[i];
            count++;
            break;
        }

        if (! count)
            return notify_fail("你并没有装备这样东西。\n");
    }

    return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
    string str, file;
    object *inv;
    int i, total = 1;

    if (! objectp(ob))
        return notify_fail("你身上没有这样东西！\n");

    if (!ob->query_temp("equipped"))
        return notify_fail("你并没有装备这样东西！\n");

    if (ob->unequip())
    {
        if (!(str = ob->query("remove_msg")))
            switch(ob->query("equip_info")["type"])
            {
                case "weapon":
                    str = "$ME收回了手中的武器" + ob->name() + "。";
                    break;
                case "accessory":
                    str = "$ME将装备着的" + ob->name() + "取了下来。";
                    break;
                default:
                    str = "$ME将装备着的" + ob->name() + "脱了下来。";
            }
        msg("vision", str, me);

        file = base_name(ob);
        inv = all_inventory(me);

        for (i = 0; i < sizeof(inv); i++)
        {
            if (inv[i] == ob) continue;
            if (base_name(inv[i]) == file)
            {
                total += (int)inv[i]->query_amount();
                destruct(inv[i]);
            }
        }
        ob->set_amount(total);

        return 1;
    } else
        return 0;
}

int help()
{
    write(@HELP
指令格式 : remove all | <装备名称>

这个指令让你脱掉身上某件装备.

HELP );
    return 1;
}
