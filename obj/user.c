inherit _LIVING;

// 判断是否 user 对象，和 efun userp() 稍有区别
int is_user() { return 1; }

void net_dead()
{
    set_temp("net_dead", 1);
    set_heart_beat(0);
    call_out("user_dest", 60);
    say(query("name") + "断线了。\n");
}

/**
 * 以下为自定义方法
 */
string get_id()
{
    string id;

    id = geteuid();
    if (!id) id = getuid();
    if (!id) query("id");

    return id;
}

string query_save_file()
{
    return sprintf(DATA_DIR "user/%s", get_id());
}

// called by the LOGIN_D when a net_dead player reconnects.
void reconnect()
{
    set_heart_beat(1);
    delete_temp("net_dead");
    remove_call_out("user_dest");
    tell_object(this_object(), "重新连线完毕。\n");
}

void user_dest()
{
    if (environment())
    {
        tell_room(environment(), query("name") + "断线超过 1 分钟，自动退出这个世界。\n");
    }
    command("quit");
}

// 从游戏中移除这个玩家
void remove()
{
    // 玩家数据存档
    command("save");
    destruct(this_object());
}
