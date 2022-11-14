/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: item.c
Description: 游戏道具标准继承对象 STD_ITEM
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
inherit _ITEM;

void create()
{
    set_name("怪物铜币", ({"coin"}));
    set("long", "只有特殊的魔物才会拥有的铜币，可以卖了赚钱。");
    set("unit", "个");
    set("base_value", 20);
    set("value", 100);
}
