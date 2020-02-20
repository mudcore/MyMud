// LOGIN_D:用户登录守护进程
inherit CORE_LOGIN_D;

// 进入游戏
void enter_world(object ob, object user)
{
    user->set_temp("login_ob", ob);
    ob->set_temp("user_ob", user);
    if (interactive(ob))
        exec(user, ob);

    user->setup(); // 激活玩家角色
    user->set("last_login_ip", ob->query_temp("ip_number"));
    user->set("last_login_at", time());
    user->set("last_saved_at", time());
    user->add("login_times", 1);
    user->save(); // 保存玩家数据
    ob->save();   // 保存账号数据

    user->move(START_ROOM);
    tell_room(START_ROOM, user->short() + "连线进入这个世界。\n", ({user}));
}
