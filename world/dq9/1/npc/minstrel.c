inherit STD_NPC;

void create()
{
    ::create("minstrel", 15);
    set_name("旅艺人布丁", ({"minstrel pudding", "pudding"}));
    set("long", "这是一个女性冒险者，她穿着奇异的服装，腰部还围着一条皮鞭。");
    set("gender", "女性");
    set("action", ([
        "msg" : ({
            "旅艺人可以使用鞭、扇、剑、盾做武器呢。",
            "如果你想成为旅艺人，我可以提供帮助哦。",
        }),
        "chance" : 1000,
    ]));
}
