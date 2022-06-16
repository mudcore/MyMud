inherit STD_NPC;

void create()
{
    ::create("ranger", 25);
    set_name("怪物猎人", ({"monster hunter", "hunter"}));
    set("long", "一个专门猎杀各种魔物的猎人，他也发布各种赏金任务。");
    set("gender", "男性");
    set("action", ([
        "msg":({
            "想成为勇士吗？来我这里接受挑战(quest hunter)吧。",
            "击杀当前地区的魔物，我可以给你丰富报酬。",
            }),
        "chance":1500,
    ]));
}
