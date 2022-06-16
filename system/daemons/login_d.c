/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_d.c
Description:用户登录系统守护进程 LOGIN_D
Author: xuefeng
Version: v1.0
Date: 2019-03-12
*****************************************************************************/
inherit CORE_LOGIN_D;

#define MUDINFO_CMD "/cmds/std/mudinfo"

private void create()
{
    string *banned_name = ({
        "习近平", "李克强"
    });
    // store_variable("banned_name", banned_name);
    add_banned_name(banned_name);
}

void wait_for_login(object login_ob, string arg)
{
    write("启动中，请稍候 ...\n");
    input_to((: wait_for_login, login_ob :));
}

// 登录入口
void login(object ob)
{
    /* 载入守护进程 */
    if (!PRELOAD_D->ready())
    {
        write(MUD_NAME + "启动中，请稍候 ...\n");
        PRELOAD_D->add_loginuser(ob);
        input_to((: wait_for_login, ob :));
        return;
    }

    write("\n");
    welcome(ob);
}

// 进入游戏
void enter_world(object ob, object user)
{
    string startroom, term_type;

    user->set_temp("login_ob", ob);
    ob->set_temp("user_ob", user);
    if (interactive(ob))
        exec(user, ob);

    user->setup();                                           // 激活玩家角色

    user->set("last_login_ip", ob->query_temp("ip_number"));
    user->set("last_login_at", time());
    user->set("last_saved_at", time());
    user->add("login_times", 1);
    user->save(); // 保存玩家数据
    ob->save();   // 保存账号数据

    // todo 检查用户资料
    if (term_type = ob->query_temp("terminal_type"))
    {
        write("客户端类型为 " + term_type + "。\n");
        user->set_temp("terminal_type", term_type);
    }
    MUDINFO_CMD->main(user);

    if (!stringp(startroom = user->query("start_room")) || !load_object(startroom))
        startroom = START_ROOM;
    if (!catch(load_object(startroom)))
    {
        user->move(startroom);
        tell_room(startroom, user->query("name") + "连线进入这个世界。\n", ({user}));
        if (user->query("login_times") == 1)
        {
            CHANNEL_D->do_channel(this_object(), "msg", sprintf("欢迎新玩家 %s 来到这个世界。", user->short()));
        }
    }
    else
    {
        // debug_message("");
    }
}

// 初始化新玩家必要属性
private void init_new_player(object user, object ob)
{
    object clothes, shoes, trousers, shield, sword;
    // 初始化玩家属性
    CHAR_D->init_player(user);
    // 初始装备
    // weapon = new(sprintf(EQUIPMENT_DIR "newbie/weapon%d.c", random(9)));
    clothes = new(EQUIPMENT_DIR "newbie/clothes.c");
    shoes = new(EQUIPMENT_DIR "newbie/shoes.c");
    trousers = new(EQUIPMENT_DIR "newbie/trousers.c");
    shield = new(EQUIPMENT_DIR "newbie/shield.c");
    sword = new(EQUIPMENT_DIR "newbie/sword.c");
    clothes->move(user);
    catch(clothes->equip());
    shoes->move(user);
    catch(shoes->equip());
    trousers->move(user);
    catch(trousers->equip());
    shield->move(user);
    catch(shield->equip());
    sword->move(user);
    catch(sword->equip());
    // 注册论坛账号
    if (env("MUDREN_ID"))
    {
        MYSQL_D->register(ob);
    }
    // 缓存到数据库
    if (env("CACHE_DATA"))
    {
        CACHE_D->insert(user, time());
    }
}
