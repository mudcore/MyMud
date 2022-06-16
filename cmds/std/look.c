#include <ansi.h>

#define SC_CMD "/cmds/std/score"

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string list_all_inventory_of_room(object me, object env);

int main(object me, string arg)
{
    object obj;
    int result;

    if (!arg)
        result = look_room(me, environment(me));
    else if ((obj = present(arg, me)) || (obj = present(arg, environment(me))))
    {
        if (obj->is_character())
            result = look_living(me, obj);
        else
            result = look_item(me, obj);
    }
    else
        result = look_room_item(me, arg);

    return result;
}

// 查看环境
int look_room(object me, object env)
{
    mapping exits;
    string str, *dirs;

    if (!env)
    {
        tell_object(me, "你的四周灰蒙蒙地一片，什么也没有。\n");
        return 1;
    }

    str = sprintf(HIC + "\n%s" + NOR + "%s\n    %s" + NOR,
                  env->short(),
                  wizardp(me) ? " - " + env : "",
                  sort_string(env->long(), 78));

    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);
        // todo 关于机关门的描述处理
        if (sizeof(dirs) == 0)
            str += "    这里没有任何明显的出路。\n";
        else if (sizeof(dirs) == 1)
            str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else
            str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                           implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs) - 1]);
    }
    else
    {
        str += "    这里没有任何出路。\n";
    }
    // 环境中的对象列表
    str += list_all_inventory_of_room(me, env);

    write(str);
    return 1;
}

int look_item(object me, object obj)
{
    // todo 实现查看物品
    return 1;
}

string look_equiped(object me, object ob)
{
    mixed *inv = all_inventory(ob);
    string str = "", subs = "";
    string pronoun;
    mapping equip_info;
    int i, n = 0;

    for (i = 0; i < sizeof(inv); i++)
    {
        if (inv[i]->query_temp("equipped"))
        {
            equip_info = inv[i]->query("equip_info");
            switch (equip_info["type"])
            {
            case "accessory":
                n++;
                subs += HIC "  [饰品]" NOR + inv[i]->short() + "\n";
                break;
            case "armor":
                n++;
                subs += HIC "  [上身]" NOR + inv[i]->short() + "\n";
                break;
            case "bracer":
                n++;
                subs += HIC "  [护腕]" NOR + inv[i]->short() + "\n";
                break;
            case "helmet":
                n++;
                subs += HIC "  [头部]" NOR + inv[i]->short() + "\n";
                break;
            case "shield":
                n++;
                subs += HIC "  [盾牌]" NOR + inv[i]->short() + "\n";
                break;
            case "shoe":
                n++;
                subs += HIC "  [脚部]" NOR + inv[i]->short() + "\n";
                break;
            case "trouser":
                n++;
                subs += HIC "  [腿部]" NOR + inv[i]->short() + "\n";
                break;
            case "weapon":
                n++;
                subs += HIC "  [武器]" NOR + inv[i]->short() + "\n";
                break;
            default:
                break;
            }
        }
    }
    if (me == ob)
    {
        pronoun = pronoun(2, me);
    }
    else
    {
        pronoun = pronoun(3, ob);
    }
    str += pronoun + "是一位 " + ob->query("lv") + " 级的" + chinese(ob->query("vocation")) + "，";
    if (n)
    {
        str += pronoun + "装备着：\n" + subs;
    }
    else if (ob->is_npc())
    {
        str += pronoun + "的装备你看不出来什么属性。";
    }
    else
    {
        str += pronoun + "没有装备任何物品。\n";
    }
    return str;
}

int look_living(object me, object ob)
{
    string msg, equip_msg;

    msg = "名称：" + ob->short() + "\n";
    msg += "说明：" + ob->query("long") + "\n";

    if (ob->is_mob())
    {
        tell_object(me, sort_string(msg, 72, 6));
        return 1;
    }

    equip_msg = look_equiped(me, ob);

    if (ob->is_npc())
    {
        msg += "      " + equip_msg;
        tell_object(me, sort_string(msg, 72, 6));
        return 1;
    }

    if (ob == me)
    {
        tell_object(me, equip_msg);
    }
    else
    {
        msg = "$ME看了看$YOU，好像对$YOU很感兴趣对样子。";
        msg("vision", msg, me, ob);
        tell_object(me, equip_msg);
        if (wizardp(me))
        {
            tell_object(me, SC_CMD->score(ob));
        }
    }

    return 1;
}

int look_room_item(object me, string arg)
{
    // todo 实现查看生物
    return 1;
}

string list_all_inventory_of_room(object me, object env)
{
    object *inv;
    object *obs;
    string str = "";

    if (!env || !me)
        return str;

    inv = all_inventory(env);
    if (!sizeof(inv))
        return str;

    obs = filter_array(inv, (: $(me) != $1 :));

    if (sizeof(obs))
    {
        mapping amount, unit;
        string short_name, *name_list;
        amount = ([]);
        unit = ([]);

        foreach(object ob in obs)
        {
            short_name = ob->short();
            if (short_name)
            {
                amount[short_name] += ob->query_temp("amount") ? ob->query_temp("amount") : 1;
                unit[short_name] = ob->query("unit") ? ob->query("unit") : "个";
            }
        }

        name_list = sort_array(keys(amount), 1);
        foreach(short_name in name_list)
        {
            str += "    ";
            if (amount[short_name] > 1)
                str += amount[short_name] + unit[short_name] + short_name + "\n";
            else
                str += short_name + "\n";
        }
    }

    return str;
}

int help(object me)
{
    write(@HELP
指令格式 : look | l [sth] | l [sth] of [sb]

这个指令可以让你查看玩家、环境、物品或玩家身上的装备等。

HELP );
    return 1;
}
