inherit STD_NPC;

void create()
{
    ::create("priest", 15);
    set_name("牧师达林", ({"priest darling", "priest", "darling"}));
    set("long", "这是沃尔罗村教堂里的牧师，据说是从海的那一边的古比亚娜城远道而来。");
    set("gender", "女性");
    set("action", ([
        "msg" : ({
            "做为普通人，哪怕日行一善，也能为我们的世界对抗魔物的破坏做出巨大的贡献。",
            "勿以善小而不为，勿以恶小而为之。",
        }),
        "chance" : 1000,
    ]));
}
