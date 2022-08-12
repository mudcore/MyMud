/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: look.c
Description: 游戏基本的look指令
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>
#include <command.h>

int look_room(object me, object env);
int look_living(object me, object ob);
int look_item(object me, object ob);
int look_room_item(object me, string arg);
string look_equiped(object me, object ob);
string desc_of_objects(object *obs);
string look_all_inventory_of_room(object me, object env);

int main(object me, string arg)
{
    object ob, env = environment(me);
    string what, where;

    if (!arg || arg == "here")
        return look_room(me, env);
    else if (sscanf(arg, "%s of %s", what, where) == 2)
    {
        if (env = present(where, env))
        {
            ob = present(what, env);
            if (objectp(ob))
            {
                if (living(ob))
                {
                    return look_living(me, ob);
                }
                else
                {
                    return look_item(me, ob);
                }
            }
        }
        return notify_fail("你感觉自己的眼神不太好 -_-!\n");
    }
    else
    {
        if (arg == "me")
            ob = this_player();
        if (!ob)
            ob = present(arg, env);
        if (objectp(ob))
        {
            if (living(ob))
            {
                return look_living(me, ob);
            }
            else
            {
                return look_item(me, ob);
            }
        }
        else if (objectp(ob = present(arg, me)))
        {
            if (ob->is_container())
                return look_room(me, ob);
            else
                return look_item(me, ob);
        }
        else if (env->is_area())
            return env->do_look(me, arg);
        else
            return look_room_item(me, arg);
    }
}

int look_room(object me, object env)
{
    string str, *dirs;
    mapping exits;

    if (!env)
    {
        tell_object(me, "你的四周灰蒙蒙地一片，什么也没有。\n");
        return 1;
    }
    if (env->is_area())
    {
        return env->do_look(me);
    }

    str = sprintf(HIC + "\n%s" + NOR + "%s\n    %s" + NOR,
                    env->short(), wizardp(me) ? " - " + env : env->coordinate(),
                    sort_string(env->long(), 72, 4));
                    // env->long());

    if (mapp(exits = env->query("exits")))
    {
        dirs = keys(exits);

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
    str += look_all_inventory_of_room(me, env);
    tell_object(me, str);
    return 1;
}

int look_room_item(object me, string arg)
{
    object env;
    mapping item, exits;

    if (!objectp(env = environment(me)))
        return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");

    if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
    {
        if (stringp(item[arg]))
            tell_object(me, item[arg]);
        else if (functionp(item[arg]))
            tell_object(me, (string)(*item[arg])(me));
        return 1;
    }

    if (mapp(exits = env->query("exits")) && stringp(exits[arg]))
    {
        if (objectp(env = load_object(exits[arg])))
        {
            say(sprintf("%s探头向%s看了看，也不知道想干什么。\n", me->query("name"), env->short()));
            return look_room(me, env);
        }
        else
            return notify_fail(arg + " 的方向好像不太正常，你啥也看不了。\n");
    }
    else
    {
        return notify_fail("你东张西望，感觉没啥可看的 -_-!\n");
    }
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

int look_item(object me, object ob)
{
    string msg;

    msg = "名称：" + ob->short() + "\n";
    msg += "说明：" + ob->query("long") + "\n";

    if (ob->is_equipment())
    {
        mapping equip_info, equip_effect;
        string extra, *list, voc_list = "", voc_list2 = "";
        int damage, defense, agi, luk, charm, ment, magic, lv, gender, i = 0;
        equip_info = ob->query("equip_info");
        equip_effect = ob->query("equip_effect");
        lv = equip_info["lv"];
        gender = equip_info["gender"];
        damage = equip_effect["damage"];
        defense = equip_effect["defense"];
        agi = equip_effect["agi"];
        luk = equip_effect["luk"];
        charm = equip_effect["charm"];
        ment = equip_effect["ment"];
        magic = equip_effect["int"];
        extra = equip_effect["extra"];

        msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
        msg += sprintf(" |%|50s| \n", MAG "*" HIY "装备效果" NOR MAG "*" NOR);
        msg += " |--------------------------------------------------| \n" NOR;

        msg += sprintf(" |%10s%-6d%11s%-6d%17s| \n", " 攻击：+", damage, "防御：+", defense, "");
        msg += sprintf(" |%10s%-6d%11s%-6d%17s| \n", " 恢复：+", ment, "魔力：+", magic, "");
        msg += sprintf(" |%10s%-6d%11s%-6d%10s%-7d| \n", " 速度：+", agi, "幸运：+", luk, "魅力：+", charm, );
        if (extra)
        {
            msg += sprintf(" |%9s%-41s| \n", " 说明：", extra);
        }
        msg += " |--------------------------------------------------| \n" NOR;
        if (sizeof(equip_info["vocation"]))
        {
            list = map_array(equip_info["vocation"], "vocation");
            foreach (string voc in list)
            {
                i++;
                if (i < 7)
                {
                    voc_list += voc + " ";
                }
                else
                {
                    voc_list2 += voc + " ";
                }
            }
        }
        msg += sprintf(" |%9s%-41s| \n", " 职业：", strlen(voc_list) ? voc_list : "全部");
        if (voc_list2 != "")
        {
            msg += sprintf(" |%9s%-41s| \n", "", voc_list2);
        }
        if (lv > 1)
        {
            msg += sprintf(" |%9s%-41d| \n", "等级：", lv);
        }
        if (gender)
        {
            msg += sprintf(" |%9s%-41s| \n", "性别：", (gender == 1) ? "男性" : "女性");
        }
        msg += HIC "≡" HIY "----------------------------------------------------" HIC "≡\n" NOR;
    }
    else
    {
        // todo 其他类型物品的额外描述
    }
    tell_object(me, sort_string(msg, 72, 6));
    // return notify_fail("这里啥也看不清呀 T_T\n");
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

string desc_of_objects(object *obs)
{
    int i;
    string str;
    mapping list, unit;
    string short_name;
    string *ob;

    if (obs && sizeof(obs) > 0)
    {
        str = "";
        list = ([]);
        unit = ([]);

        for (i = 0; i < sizeof(obs); i++)
        {
            string title;

            if (!userp(obs[i]) && QUEST_D->hasQuest(this_player(), obs[i]))
                short_name = sprintf("%s", BLINK + HIY "！" NOR);
            else
                short_name = "";
            if (title = obs[i]->query("title"))
            {
                short_name += HIY + title + NOR "·" + obs[i]->short();
            }
            else
            {
                short_name += obs[i]->short();
            }

            list[short_name] += obs[i]->query_temp("amount") ? obs[i]->query_temp("amount") : 1;
            unit[short_name] = obs[i]->query("unit") ? obs[i]->query("unit") : "个";
        }

        ob = sort_array(keys(list), 1);
        for (i = 0; i < sizeof(ob); i++)
        {
            str += "  ";
            if (list[ob[i]] > 1)
                str += list[ob[i]] + unit[ob[i]] + ob[i] + "\n";
            else
                str += ob[i] + "\n";
        }
        return str;
    }

    return "";
}

string look_all_inventory_of_room(object me, object env)
{
    object *inv;
    object *obs;
    string str = "";

    if (!env || !me)
        return "";

    inv = all_inventory(env);
    if (!sizeof(inv))
        return str;

    obs = filter_array(inv, (: $(me) != $1 :));
    str += desc_of_objects(obs);

    return str;
}

string vocation(string voc)
{
    return chinese(voc);
}

int help(object me)
{
    write(@HELP
指令格式 : look | l [sth] | l [sth] of [sb]

这个指令可以让你查看玩家、环境、物品或玩家身上的装备等。

HELP );
    return 1;
}
