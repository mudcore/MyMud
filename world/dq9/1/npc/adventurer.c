inherit STD_NPC;

void create()
{
    ::create("common", 5);
    set_name("休息的冒险者", ({"guest", "adventurer"}));
    set("long", "这是一个受伤的冒险者，正在这里休息恢复体力。");
    set("action", ([
        "msg" : ({
            "我曾经在野外发现了勇者之塔，里面好多怪物啊，差点回不来了",
            "我现在只想好好休息一下，不过我还需要一些草药，哪位好心人能帮帮呀？",
            "在旅店休息也能自然的回复体力，可惜魔力没法回复呀。",
        }),
        "chance" : 1000,
    ]));
}
