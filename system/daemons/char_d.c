// 初始化玩家角色
void init_player(object user)
{
    user->set("birthday", time());
    user->set("lv", 1);  // 等级
    user->set("exp", 0); // 经验
    // 设置玩家属性
    user->set_attr("max_hp", 50);
    user->set_attr("max_mp", 5);
    user->set_attr("str", 10);
    user->set_attr("agi", 8);
    user->set_attr("vit", 5);
    user->set_attr("int", 5);
    user->set_attr("dex", 7);
    user->set_attr("luk", 10);
    user->set_attr("chao", 0);
}

void setup(object ob)
{
    if(!ob->query_hp())
        ob->set_attr("hp", ob->query_max_hp());
}
