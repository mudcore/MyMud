inherit STD_NPC;

private create()
{
    ::create("common", random(10));
    set_name("村民", ({"villager"}));
    set("long", "这是一个普通的村民，祖祖辈辈都居住在沃尔罗村。");
    set("gender", random(2) ? "男性" : "女性");
}
