/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: divine_officer.c
Description: 达玛神官
Author: xuefeng
Version: v1.0
*****************************************************************************/
#include <ansi.h>
inherit STD_DIVINE;

protected void create()
{
    ::create("sage", 90);
    set_name("达玛神官", ({"divine officer"}));
    set("long", HIG "这是达玛神殿的管理者，可以为冒险者提供转职和转生服务。" NOR);
    set("gender", "女性");
    set("action", ([
        "msg" : ({
            "冒险者的基础职业有旅艺人、僧侣、魔法师、盗贼、战士和武斗家6种。",
            "冒险者的上级职业有战斗大师、魔法战士、游侠、贤者、圣骑士和超级明星6种。",
            "每种职业都有5可系列的职业技能可以学习，已经学习的技能在转职后继续保留。",
            "不同职业可以掌握的魔法咒文不同，而且转职不会保留已经学习的咒文。",
            "每种职业的等级上限是99级，达到99的冒险者可以转生到新的世界从新开始冒险。",
        }),
        "chance" : 200,
    ]));
}

void init()
{
    object ob;
    if (interactive(ob = this_player()))
    {
        add_action("change_vocation", "vocation");
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }

}

int change_vocation(string arg)
{
    string msg, *voc_list = ({
        "warrior", "priest", "mage", "martial-artist",
        "thief", "minstrel", "gladiator", "paladin",
        "armament-alist", "ranger", "sage", "luminary",
        });
    object me = this_player();
    if (!arg)
    {
        msg = "$YOU对$ME说到：“转职请使用 vocation 职业ID，如：vocation minstrel”。\n";
        msg("info", msg, me, this_object());
        msg = HIY "当前可以转职的职业：\n";
        msg += "\t - 战士(warrior)、僧侣(priest)、魔法师(mage)\n";
        msg += "\t - 武斗家(martial-artist)、盗贼(thief)、旅艺人(minstrel)\n";
        msg += "\t - 战斗大师(gladiator)、圣骑士(paladin)、魔法战士(armament-alist)\n";
        msg += "\t - 游侠(ranger)、贤者(sage)、超级明星(luminary)\n" NOR;
        tell_object(me, msg);
    }
    else if (member_array(arg, voc_list) < 0)
    {
        return notify_fail(HIR "你不能转职成这个职业。\n" NOR);
    }
    else
    {
        if (sizeof(me->query_temp("equip")))
        {
            return notify_fail(HIR "请脱掉装备后再来转职吧。\n" NOR);
        }
        if (VOCATION_D->change_vocation(me, arg))
        {
            cecho("恭喜你，冒险者，转职成功！");
            if (me->query("vocation") == "minstrel" && !me->query("bag"))
            {
                me->set("bag", 1);
                write(HIY "你获得 1 个冒险者背包！(使用方法：bag | store | take)\n" NOR);
            }
        }
    }
    return 1;
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment()) return;
    msg("info", "$YOU对$ME说到：“远道而来的冒险者啊，需要转职(vocation)吗？”", ob, this_object());
}
