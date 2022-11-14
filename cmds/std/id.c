/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: id.c
Description: 显示对象id
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object *inv;
    string name;
    int i;

    if (! arg)
    {
        inv = all_inventory(me);
        if (! sizeof(inv))
            return notify_fail("你身上没有任何东西。\n");
        write("你身上携带物品的(英文)名称如下：\n");
        for(i = 0; i < sizeof(inv); i++)
        {
            name = inv[i]->name();
            write(sprintf("%-10s = %s\n", remove_ansi(name),
                    implode(inv[i]->id_list(), "、")));
        }
        return 1;
    }

    if (arg == "here")
    {
        inv = all_inventory(environment(me));
        if (! sizeof(inv))
            return notify_fail("这里没有任何东西。\n");
        write("在这个房间中的生物及物品的(英文)名称如下：\n");
        for(i = 0; i < sizeof(inv); i++)
        {
            name = inv[i]->name();
            if (sizeof(inv[i]->id_list()))
            {
                write(sprintf("%-10s = %s\n", remove_ansi(name),
                              implode(inv[i]->id_list(), "、")));
            }
        }
        return 1;
    }
}

int help(object me)
{
    write(@HELP
指令格式 : id [here]

这个指令可以让你知道物品的英文名称及名字. 只打 id 会显示
你身上所携带物品的名称. 'id here' 则显示所有跟你在同一个
环境里的对象名称.

HELP );
    return 1;
}
