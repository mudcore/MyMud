/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_inventory.c
Description: 玩家随身物品存取功能接口
Author: xuefeng
Version: v1.0
Date: 2019-03-18
History:
*****************************************************************************/
#include <ansi.h>

#define AMOUNT 0
#define TEMP_DATABASE 1

mapping my_inventory;

// 物品保存功能
void save_inventory()
{
    string basename;
    mapping save_inventory_list = allocate_mapping(0);
    int amount;

    foreach (object ob in all_inventory(this_object()))
    {
        basename = base_name(ob);

        if (!arrayp(save_inventory_list[basename]))
            save_inventory_list[basename] = allocate(2);
        if (!arrayp(save_inventory_list[basename][TEMP_DATABASE]))
            save_inventory_list[basename][TEMP_DATABASE] = allocate(0);

        if (!(amount = ob->query_temp("amount")))
            amount = 1;
        save_inventory_list[basename][AMOUNT] += amount;
        save_inventory_list[basename][TEMP_DATABASE] += ({ob->query_entire_temp_dbase()});
    }

    if (!sizeof(save_inventory_list))
        my_inventory = ([]);
    else
        my_inventory = save_inventory_list;
}

void restore_inventory()
{
    int index, int_amount;
    object ob, newob;
    mapping save_inventory_list = my_inventory;

    if (!sizeof(save_inventory_list))
        return;

    foreach (string filename, mixed info in save_inventory_list)
    {
        index = 0;

        if (!objectp(ob = new (filename)))
        {
            tell_object(this_object(), HIR "请注意：你身上有些物品被系统回收了。\n" NOR);
            continue;
        }
        else
        {
            ob->set_temp_dbase(info[TEMP_DATABASE][index++]);

            if (ob->is_unique())
            {
                if (ob->query_temp("equipped"))
                {
                    ob->delete_temp("equipped");
                    ob->set_temp("equip", 1); // 很重要的标记，避免被ITEM合并
                    ob->move(this_object());
                    ob->equip();
                }
                else
                    ob->move(this_object());
            }
            else
            {
                int_amount = sizeof(info[TEMP_DATABASE]);

                if (ob->query_temp("equipped"))
                {
                    ob->delete_temp("equipped");
                    ob->set_temp("equip", 1); // 很重要的标记，避免被ITEM合并
                    ob->move(this_object());
                    ob->equip();
                }
                else
                {
                    ob->move(this_object());
                }

                while (--int_amount)
                {
                    catch (newob = new (filename));
                    catch (newob->set_temp_dbase(info[TEMP_DATABASE][index++]));
                    if (newob->query_temp("equipped"))
                    {
                        newob->delete_temp("equipped");
                        newob->set_temp("equip", 1); // 很重要的标记，避免被ITEM合并
                        newob->move(this_object());
                        newob->equip();
                    }
                    else
                    {
                        newob->move(this_object());
                    }
                }
            }
        }
    }
}
