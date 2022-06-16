inherit STD_NPC;

void create()
{
    ::create("mage", 15);
    set_name("受伤的冒险者", ({"adventurer"}));
    set("long", "这是一个受伤的冒险者，正在这里休息恢复体力。");
    set("action", ([
        "msg" : ({
            "遗迹里的魔物也太多了，差点回不来了……",
            "我现在没有魔力了，哪位好心人能帮帮忙给点魔法圣水呀？",
        }),
        "chance" : 1000,
    ]));
}
