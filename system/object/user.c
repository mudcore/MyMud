/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user.c
Description: 用户连线对象 USER_OB
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>

inherit _USER;

string get_id();

/*
void init()
{
    // using "" as the second argument to add_action() causes the driver
    // to call command_hook() for those user inputs not matched by other
    // add_action defined commands (thus 'command_hook' becomes the default
    // action for those verbs without an explicitly associated action).

    debug_message("[USER_OB]->init():" + this_object() + "(" + this_user() + ")!\n");
    if (this_object() == this_player()) {
        add_action("command_hook", "", 1);
    }
}
*/

void window_size(int width, int height)
{
    set_temp("window_size/width", width);
    set_temp("window_size/height", height);
    message("system", "终端窗口大小设置为 " + width + " × " + height + "。\n", this_object());
}

void receive_environ(string var, string value)
{
    set_temp("env/" + var, value);
}

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
