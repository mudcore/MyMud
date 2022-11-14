// cache.c
#include <ansi.h>

inherit _CLEAN_UP;

private void search_dir(object me);
private void examine_player(string name, int last_touched);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    if (arg != "-all")
        return notify_fail("指令格式：cache -all\n");

    shout(BCC(208) "※ 系统进行数据处理中，请耐心等候..." NOR "\n");
    write(HIG "系统开始缓存所有玩家基本数据...\n" HIG "进度：" + process_bar(0) + "\n");

    search_dir(me);

    return 1;
}

private void search_dir(object me)
{
    string *dir;
    string name;
    int i;

    // 初始化数据库
    CACHE_D->init_db();
    dir = get_dir(DATA_DIR + "login/", -1);

    for (i = 0; i < sizeof(dir); i++)
    {
        reset_eval_cost();
        if (sscanf(dir[i][0], "%s.o", name) == 1)
        {
            examine_player(name, dir[i][2]);
        }
        message("system", ESC + "[1A" + ESC + "[256D" HIG "进度：" + process_bar((i + 1) * 100 / sizeof(dir)) + "\n",
                me ? me : filter_array(users(), (: wizardp :)));
    }
}

private void examine_player(string name, int last_touched)
{
    object login_ob;
    object user_ob;
    int online;
    mixed *st;

    if (!last_touched)
    {
        st = stat(DATA_DIR + "login/" + name + __SAVE_EXTENSION__);

        if (!arrayp(st) || sizeof(st) < 3)
            // 可能没有这个文件
            return;

        last_touched = st[1];
    }

    login_ob = new (LOGIN_OB);
    login_ob->set("id", name);

    if (!login_ob->restore())
    {
        destruct(login_ob);
        return;
    }

    if (login_ob->query("id") != name)
    {
        destruct(login_ob);
        return;
    }

    if (!objectp(user_ob = find_player(name)))
    {
        online = 0;
        user_ob = LOGIN_D->make_body(login_ob);
        if (!user_ob)
        {
            destruct(login_ob);
            return;
        }

        if (!user_ob->restore())
        {
            destruct(login_ob);
            destruct(user_ob);
            return;
        }
    }
    else
        online = 1;

    CACHE_D->insert(user_ob, last_touched);

    if (!online)
    {
        destruct(user_ob);
    }
    destruct(login_ob);
}

int help(object me)
{
    write(@HELP
指令格式：cache -all

缓存玩家数据到·data/db.sqlite·

HELP
    );
    return  1;
}
