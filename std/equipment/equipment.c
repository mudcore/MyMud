/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: equipment.c
Description: 装备标准继承对象 STD_EQUIPMENT
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
    Sword/Spear/Knife/Wand/Whip/Staff/Claw/Fan/Axe/Hammer/Boomerang/Bow/Fist/Shield
*****************************************************************************/
inherit _EQUIPMENT;

void create()
{
    set("unit", "件");
    set("equip_msg", 0); // 装备上道具时的显示信息：$ME代表自己
    set("remove_msg", 0); // 取下装备时的信息显示：$ME代表自己
    set("base_value", 50); // 卖给ＮＰＣ
    set("value", 250); // 从ＮＰＣ购买
}
