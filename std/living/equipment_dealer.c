/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: equipment_dealer.c
Description: 装备商人标准继承对象 STD_DEALER_E
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
    set_name("装备商人", ({"dealer"}));
    set("long", HIC "一个商贩，专门买卖各种武器装备。" NOR);
    set("vendor_goods", ({
    }));
}
