inherit STD_NPC;

private create()
{
    string *vocation_list = ({
        "warrior",
        "priest",
        "mage",
        "martial-artist",
        "thief",
        "minstrel",
        "gladiator",
        "paladin",
        "armament-alist",
        "ranger",
        "sage",
        "luminary",
    });

    ::create(element_of(vocation_list));
    set_name("天使", ({"angel"}));
    set("long", "这是一位守护世界的天使。");
    set("gender", random(2) ? "男性" : "女性");
}
