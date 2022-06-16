/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: item_dealer.c
Description: 物品商人标准继承对象 STD_DEALER_I
Author: xuefeng
Version: v1.0
Date: 2019-03-13
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_DEALER;

protected varargs void create(string vocation, int lvl)
{
    ::create(vocation, lvl);
    set_name("杂货商贩", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种千奇百怪但又实用的杂货。" NOR);
    set("vendor_goods", ({
    }));
}
