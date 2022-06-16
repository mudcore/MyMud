/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: magic.c
Description: 游戏魔法道具标准继承对象 STD_MAGIC
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_ITEM;

void create()
{
    ::create();
    set_name(YEL "奇美拉之翼" NOR, ({"chimaera wing", "chimaera", "wing", "11"}));
    set("long", "使用(use)后可以飞回到最近做过祈祷的城镇教堂。");
    set("base_value", 250);
    set("value", 1500);
    set("unit", "对");
    set("effect", ([
        "action" : "home", // 使用特殊行动
        // "spell":"", // 使用咒文
        // "skill":"", // 使用特技
    ]));
}

int do_effect(object me)
{
    mapping effect = query("effect");
    string name = query("name"), msg, action;
    object env = environment(me);

    msg = HIC "$ME使用了" + name + HIC "。";

    if (mapp(effect))
    {
        if (action = effect["action"])
        {
            switch (action)
            {
            case "home":
                if (env->query("outdoors"))
                {
                    string rebornroom;
                    if (stringp(rebornroom = me->query("reborn_room")))
                    {
                        // 因为环境变了，所以需要提前显示信息
                        msg("default", msg, me);
                        me->move(rebornroom);
                        me->start_busy(2);
                        add_amount(-1);
                        return 1;
                    }
                    else
                    {
                        msg += "但是$ME迷失了方向，只好飞回到原地。";
                    }
                } else
                {
                    msg += "但是$ME撞到墙上摔的头晕眼花。";
                    me->start_busy(3);
                }
                break;

            default:
                break;
            }
        }
    }

    msg("default", msg, me);
    add_amount(-1);
    return 1;
}
