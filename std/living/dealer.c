/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: dealer.c
Description: 商人标准继承对象 STD_DEALER
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_NPC;
inherit _DEALER;

protected varargs void create(string vocation, int lvl)
{
    if (!stringp(vocation))
    {
        vocation = "common";
    }
    if (!lvl)
    {
        lvl = 20;
    }
    npc::create(vocation, lvl);
    set_name("杂货商", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种千奇百怪但又实用的杂货。" NOR);
    set("gender", "男性");
    set("vendor_goods", ({
    }));
}

void init()
{
    add_action("do_buy", "buy");
    add_action("do_list", "list");
    add_action("do_sell", "sell");
    add_action("do_show", "show");
}
