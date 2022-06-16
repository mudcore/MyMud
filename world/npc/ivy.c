#include <ansi.h>

inherit STD_NPC;

void create()
{
    ::create("sage", 99);
    set_name(HIY "艾薇" NOR, ({"ivy"}));
    set("long", "她是守护世界的天使，也是天使界的长老，代表女神守护在这里。");
    set("gender", "女性");
    set("title", "大天使");
    set("action", ([
        "msg" : ({
            "如果你在冒险中遇到困难需要查看帮助，请输入 help newbie",
            "想查看有多少天使在为拯救世界而努力，请输入 who",
            "想查看你掌握的咒文魔法，请输入 spell 或 magic",
            "想查看你的职业技能，请输入 skill 和 skills",
            "想查看天使们的各种排行榜，请输入 top",
            "想查看地图，请输入 map 和 map here",
            "想查看你的个人资料和状态，请输入 sc 和 hp",
            "想和远在世界各处的其他天使聊天，请输入 chat 或 bill 或 shout",
            "如果你需要接任务或完成任务，请输入 quest [id]",
            "你可以在世界的任何地方输入 `chat @ivy help` 和我对话~",
        }),
        "chance" : 100,
    ]));
}

void receive_report(object user, string verb, string arg)
{
    if (sscanf(arg, "@ivy %s", arg) == 1)
    {
        call_out("iqa", 1, user, verb, arg);
    }
}

void iqa(object ob, string verb, string arg)
{
    string help;
    if (arg == "help")
    {
        help = @HELP
天使艾薇聊天指南：chat @ivy 内容
如：
    chat @ivy 北京明天天气      可查看天气预报
    chat @ivy 成语接龙          可挑战成语接龙
    chat @ivy 心理测试          可做自我人格测试
    chat @ivy 唐诗宋词          可学习中华诗词
    chat @ivy 鬼故事            可听艾薇讲故事
    chat @ivy 新闻              可阅读最新新闻
    chat @ivy 帮助              可了解游戏玩法

更多功能请多和天使艾薇聊天探索发现吧~
HELP;
        CHANNEL_D->do_channel(this_object(), "chat", help);
    }
    else if (arg == "帮助")
    {
        help = @HELP
勇者斗恶龙MUD游戏指南：
    help            -   游戏基本指令列表
    help newbie     -   新手玩家入门
    help tutorial   -   游戏常见问题指南
-------------------------------------------------------
更多游戏帮助请看论坛（https://bbs.mud.ren/nodes/5）或输入指令 bbs
HELP;
        CHANNEL_D->do_channel(this_object(), "chat", help);
    }
    else
    {
        "/system/daemons/iqa_d"->main(this_object(), arg);
    }
}
