#include <ansi.h>

inherit STD_ITEM;

private void create()
{
    set_name("勇者斗恶龙编年史", ({"dq book", "dq", "book"}));
    set("unit", "本");
    set("long", @LONG
这是勇者斗恶龙世界的历史，如果你感兴趣的话，可以阅读(read)。
    勇者斗恶龙系列（ドラゴンクエスト，Doragon Kuesuto，Dragon Quest）是由日本艾尼克斯（现为史克威尔艾尼克斯）研发的电子角色扮演游戏（RPG）系列，其作为游戏史上最畅销的长寿游戏系列之一，在日本具有“国民RPG”之称。
    本游戏是在第九代的背景下开发的同人MUD游戏，职业系统和魔物系统完全参考DQ9。
LONG
    );
}

void init()
{
    add_action("do_read", "read");
}

int do_read(string arg)
{
    string *capter;
    capter = ({
        "第01代：勇者斗恶龙",
        "第02代：恶灵的众神",
        "第03代：接着迈向传说",
        "第04代：被引导的人们",
        "第05代：天空的新娘",
        "第06代：幻之大地",
        "第07代：伊甸的战士们",
        "第08代：天空、海洋、大地与被诅咒的公主",
        "第09代：星空的守护者",
        "第10代：勇者斗恶龙 Online",
        "第11代：寻觅逝去的时光",
    });
    say(this_player()->query("name") + "开始阅读《勇者斗恶龙》。\n");
    write("你开始阅读勇者斗恶龙《" + element_of(capter) + "》的历史故事。\n");
    return 1;
}
