/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: divine.c
Description: 托拉佩塔城教堂的神父
Author: xuefeng
Version: v1.0
Date: 2019-03-15
History:
*****************************************************************************/
#include <ansi.h>
inherit STD_DIVINE;

protected void create()
{
    ::create();
    set_name("转职牧师", ({"priest"}));
    set("long", HIG "托拉佩塔城教堂的牧师，可以在她这里申请转职(vocation)。" NOR);
    set("gender", "女性");
}

void init()
{
    add_action("change_vocation", "vocation");
}

int change_vocation(string arg){
    string msg;
    object me = this_player();
    if (!arg) {
        msg = "$YOU对$ME说到：“转职请使用 vocation 职业ID，如：vocation warrior”。\n";
        msg += "当前可以转职的职业如下：warrior priest mage martial-artist thief";
        msg("vision", msg, me, this_object());
    } else {
        if (VOCATION_D->change_vocation(me, arg)){
            write(BRED "恭喜你，冒险者，转职成功！\n" NOR);
        }
    }
    return 1;
}
