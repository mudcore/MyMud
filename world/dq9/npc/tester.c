/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: tester.c
Description: 游戏测试用NPC
Author: xuefeng
Version: v1.0
*****************************************************************************/
#include <ansi.h>
inherit STD_NPC;

void do_list();

protected void create()
{
    ::create("luminary", 99);
    set_name("游戏测试员", ({"game tester"}));
    set("long", HIM "这是一个游戏测试NPC，目前可以用来测试未开放的地区，让玩家直接进入对应区域体验游戏并快速升级。" NOR);
    set("action", ([
        "msg":({
            "输入 area 可以查看目前可测试的未开放地区，输入 area + 地区ID 可进入对应地区体验游戏。",
            "测试未开放地区需要一定的等级和金币，请注意，不要去危险的地区，否则后果自负哦。",
            "目前测试地区仅仅可以测试魔物，无法体验剧情，区域中除了魔物几乎什么都见不到。",
            "所有未开放地区都是无限地图，你永远也走不到边界，如果要离开，只有使用奇美拉之翼飞回来。",
            "在游戏的部分地区中会遇到勇者之塔，你可以从塔中的传送门回到天使界哦。",
            }),
        "chance":1000,
    ]));
}

void init()
{
    object ob;
    add_action("do_test", "area");
    if (interactive(ob = this_player()))
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

int do_test(string arg)
{
    if (!arg)
    {
        do_list();
        return notify_fail("输入 area id 进入列表中的区域。\n");
    }
    else
    {
        int area = atoi(arg);
        object me = this_player();

        if (area < 10 || area > 41)
        {
            return notify_fail("地区 ID 错误。\n");
        }

        if (me->query("lv") < area + 20)
        {
            return notify_fail("你的等级不到 " + (area + 20) + " 级，去这个地方太冒险了。\n");
        }

        if (me->query("coin") >= area * 250)
        {
            object world;
            string map;
            int *wild = ({10, 13, 14, 15, 16, 17, 19, 20, 22, 23, 24, 25, 26, 28, 30, 31, 33, 35});
            int *dungeon = ({12, 18, 21, 27, 29, 32, 34, 36, 37, 38, 39, 40, 41});

            if (member_array(area, wild) >= 0)
            {
                map = "/wild";
            }
            else if (member_array(area, dungeon) >= 0)
            {
                map = "/dungeon";
            }
            else
                map = "/tower";

            if (!(world = load_object(WORLD_9_DIR + area + map)))
            {
                return notify_fail("你只能去列表中的地区。\n");
            }
            me->set_all_full();
            me->add("coin", -(area * 250));
            me->move(world);
            return 1;
        }
        return notify_fail("传送到此地区需要支付 " + area * 250 +" 金币。\n");
    }
}

varargs void greeting(object ob, object me)
{
    ob = ob || this_player();
    me = me || this_object();
    if ((environment(me)->is_area() && !area_environment(ob, me)) || environment(ob) != environment(me))
        return;
    msg("info", "$ME对$YOU说到：“我这里可以让你直接去这个世界任何地方(area)，你想测试体验吗？”", me, ob);
}

void do_list()
{
    string list;
    list = @AREA
------------------------------------------------------------------
 ID         地区                    ID        地区
 10     达玛岛                      23     亚汗湿地
 13     贝伦海岸                    24     卡尔瓦多大草原
 14     卡拉克塔荒野                25     达达玛鲁达山
 15     皮塔利平原                  26     卡兹奇奇山
 16     皮塔利山脉                  28     艾玛尼安雪原
 17     萨玛隆                      30     东纳札姆区域
 19     皮塔利海岸                  31     西纳札姆区域
 20     古比亚娜沙漠                33     龙眠之地
 22     阿什巴尔地区                35     迦南帝国

 以上地区可以直接使用奇美拉之翼飞回你祈祷过的教堂。
-------------------------------------------------------------
 ID         地区                    ID       地区
 11     达玛之塔                    34     德米尔火山
 12     海滨洞窟                    36     绝望与憎恶魔宫
 18     萨玛隆洞窟                  37     宝藏洞窟
 21     古比亚娜城                  38     宝藏洞窟
 27     卡兹恰村落                  39     宝藏洞窟
 29     艾鲁希昂学院地下迷宫        40     宝藏洞窟
 32     魔兽洞窟                    41     宝藏洞窟

 以上地区为地牢或室内地形，你必须找到出口到室外后才能使用奇美拉之翼。
------------------------------------------------------------------
AREA;
    cecho(list);
}
