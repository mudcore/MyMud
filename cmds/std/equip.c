// wield.c
#include <ansi.h>
inherit _CLEAN_UP;

int do_equip(object me, object ob);

int main(object me, string arg)
{
    object ob, *inv;
    int i, count;

    if (! arg) return notify_fail("你要装备什么？\n");

    if (arg == "all")
    {
        inv = all_inventory(me);
        for (count = 0, i = 0; i<sizeof(inv); i++)
        {
            if (inv[i]->query_temp("equipped")) continue;
            if (do_equip(me, inv[i]))
                count ++;
        }
        write("Ok.\n");
        return 1;
    }

    if (! objectp(ob = present(arg, me)))
        return notify_fail("你身上没有这样东西。\n");

    if (ob->query_temp("equipped")) {
        return notify_fail("你已经装备着了。\n");
    }
    if (!ob->is_equipment()) {
        return notify_fail("这件物品不是装备。\n");
    }

    return do_equip(me, ob);
}

int do_equip(object me, object ob)
{
    string str;
    object obj;

    if (ob->query_temp("amount") > 1){
        ob->add_amount(-1);
        obj = new(base_name(ob));
        obj->set_temp("equip", 1); // 很重要的标记，避免被ITEM合并
        obj->set_temp("amount", 1);
        obj->move(me);
    } else obj = ob;

    if (obj->equip())
    {
        if (!(str = obj->query("equip_msg")))
            str = "$ME装备了" + obj->name() + "。";
        msg("vision", str, me);
        return 1;
    } else
        return 0;
}

int help(object me)
{
    write(@HELP
指令格式：equip all | <装备名称>

这个指令让你装备上自己身上的某件武器、防具或饰品。

HELP );
    return 1;
}
