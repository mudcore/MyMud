/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: debug.c
Description: 管理员测试系统用，包括efun功能测试及其它代码片断测试
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>
#include <command.h>
#include <runtime_config.h>

inherit _CLEAN_UP;

int help(object me);
void debug(string);
int *slice(int *mob, int range);
void close_callback(int fd);

string debug_str;
mapping debug_map;

nosave int s = 0; // socket

/**
 * efun test
 */

/** Arrays
 *  allocate
 *  arrayp
 *  filter_array
 *  map_array
 *  member_array
 *  pointerp
 *  sort_array
 *  unique_array
 */
void test_array()
{
    mixed *arr;

    debug("allocate an array:");
    arr = allocate(1 + random(10), (: $1 :));
    printf("arr : %2@d\n", arr);
    arr[0] = allocate(1 + random(10), (: $1 :));
    arr[0][0] = allocate(1 + random(10), (: $1 :));

    debug("element_of(arr) = " + element_of(arr));


    print_r(arr);
}

// Calls
void test_call_other(object me)
{
    debug(call_other(me, "query", "name"));
    print_r(call_other(objects(), ({"query", "name"})));
}

void test_call_out()
{
    debug("开始倒记时！");
    call_out("debug", 10, "倒记时10秒!");
    call_out("debug", 20, "倒记时20秒!");
    call_out("debug", 30, "倒记时30秒!");
    print_r(call_out_info());
}

void test_object()
{
    debug("this_object:" + this_object());
    debug("previous_object:" + previous_object());
}

void test_shadow()
{
    object ob;
    shadow(load_object("/cmds/help"));
    ob = query_shadowing(this_object());
    debug("query_shadowing : " + ob);
}

void test_catch(object me)
{
    string err;

    // err = catch(me->move(START_ROOM));
    err = catch(me->move("START_ROOM"));
    if (err)
    {
        debug("catch error : " + err);
        return;
    }
}

void test_time()
{
    string str;

    debug("real_time:" + real_time());
    debug("time:" + time());
    debug("ctime:" + ctime(60));
    str = ctime();
    printf("格式化时间：%s/%s/%s %s\n", "04", (str[8] == ' ' ? "0" + str[9..9] : str[8..9]), str[ < 4.. < 1], str[11..15]);
    debug("zonetime UTC:" + zonetime("UTC", time()));
    debug("zonetime PRC:" + zonetime("PRC", time()));
    debug("is_daylight_savings_time UTC:" + is_daylight_savings_time("UTC", time()));
    debug("is_daylight_savings_time PRC:" + is_daylight_savings_time("PRC", time()));
    debug("localtime:");
    print_r(localtime(time()));
}

void test_db(string *args)
{
    mixed dbcon, dbrows, dbres;

    debug(MYSQL_D->status());
    if (sizeof(args) >= 3)
    {
        dbcon = MYSQL_D->connect(args[1]);
        debug("数据库连接结果：" + dbcon);
        if (intp(dbcon))
        {
            if (sizeof(args) == 4)
                dbrows = MYSQL_D->exec(dbcon, "SELECT " + args[3] + " FROM " + args[2]);
            else
                dbrows = MYSQL_D->exec(dbcon, "SELECT * FROM " + args[2]);
            debug("数据库查询结果：" + dbrows);
            if (intp(dbrows) && dbrows)
            {
                for (int i = 1; i <= dbrows; i++)
                {
                    dbres = MYSQL_D->fetch(dbcon, i);
                    for (int j = 0; j < sizeof(dbres); j++)
                    {
                        write(" | " + dbres[j]);
                    }
                    write(" |\n");
                }
            }
            MYSQL_D->close(dbcon);
        }
    }
    else
    {
        debug("[Warning]参数格式：db host table [field]");
    }
}

void test_filesystem(object me)
{
    string str;
    str = read_file(NOTICE, random(15), 1);
    if (stringp(str))
    {
        str = replace_string(str, "\n", "");
        debug(str);
    }
    str = read_file(NOTICE);
    if (str)
    {
        string *notice;
        notice = explode(str, "\n");
        for (int i = 0; i < sizeof(notice); i++)
        {
            if (notice[i][0] == '#')
            {
                notice[i] = 0;
            }
        }
        print_r(notice);
        notice -= ({0});
        print_r(notice);
        str = element_of(notice);
        if (!random(2))
        {
            message(element_of(({"warning", "danger", "success"})), str, me);
        }
    }
}
// void create() { seteuid(0); }

int main(object me, string arg)
{
    int err, i, j;
    string str;
    mapping map;

    mixed *arr, *args;
    function func;
    object ob, env = environment(me), *obs;

    if (!wizardp(me))
        return 0;

    if (!arg)
        return help(me);
    else
        args = explode(arg, " ");

    switch (args[0])
    {
    /**
     * arrays
     */
    case "array":
        test_array();
        break;
    /**
     * buffers
     */

    /**
     * calls
     */
    case "call_other":
        test_call_other(me);
        break;
    case "call_out":
        test_call_out();
        break;
    case "origin":
        debug("origin:" + origin());
        break;
    case "object":
        test_object();
        break;
    case "shadow":
        test_shadow();
        break;
    case "catch":
        test_catch(me);
        break;
    /**
     * contrib
     */
    case "abs":
        debug("abs(-100)=" + abs(-100));
        break;
    case "test_load":
        if (sizeof(args) == 2)
        {
            debug("test_load : " + test_load(args[1]));
        }
        break;
    case "debug_message":
        debug_message("void debug_message(string msg);");
        debug("debug_message:请打开debug.log查看结果 ^_^");
        break;

    case "time":
        test_time();
        break;

    case "get_garbage":
        print_r(get_garbage());
        break;

    /**
     * db 数据库相关测试
     */
    case "db":
        test_db(args);
        break;

    /**
     * ed
     */

    /**
     * filesystem
     */
    case "read_file":
        test_filesystem(me);
        break;
    case "stat":
        print_r(stat(__FILE__));
        print_r(stat(__DIR__));
        debug("注册玩家：" + sizeof(get_dir(DATA_DIR "user/*.o")));
        break;
    case "link":
        // link("/cmds/wiz/debug.c", "/cmds/test.c");
        break;
    case "rm":
        if (rm("/cmds/test.c"))
        {
            debug("删除成功！");
        }
        else
        {
            debug("删除失败！");
        }
        break;
    /**
     * floats
     */
    case "float":
        j = 120;
        for (i = 0; i < 10; i++)
        {
            debug(i + " " + ceil(j));
            j *= -0.01;
        }
        break;
    case "floor":
        debug("floor 7 / 3 :" + floor(7 / 3));
        break;
    case "to_int":
        debug("7 / 3 :" + 7 / 3);
        debug("7 / 3.0 :" + 7 / 3.0);
        debug("7.0 / 3 :" + 7.0 / 3);
        debug("to_int 7.0 / 3 :" + to_int(7.0 / 3));
        debug("1 / 2 :" + 1 / 2);
        debug("1 / 2.0 :" + 1 / 2.0);
        debug("to_int 1 / 2.0 :" + to_int(1 / 2.0));
        break;

    /**
     * functions
     */
    case "function":
        func = (: write, "debug function!\n" :);
        evaluate(func);
        func = (: this_player()->query("name") :);
        debug(evaluate(func));
        debug(evaluate((: $1 + $2 * $3 :), 3, 4, 5));
        break;
    /**
     * general
     */
    case "type":
        debug(typeof(err));
        break;
    case "sizeof":
        arr = ({});
        debug("size of arr = " + sizeof(arr));
        break;
    case "save_variable":
        debug_str = save_variable(allocate(1 + random(10), (: $1 :)));
        debug(debug_str);
        print_r(restore_variable(debug_str));
        debug(debug_str);
        break;
    /**
     * interactive
     */
    case "exec":
        ob = present(args[1], env);
        if (ob)
        {
            exec(ob, this_player());
        }
        break;
    case "notify_fail":
        notify_fail(BRED YEL "notify_fail\n" NOR); // return 0 will display this message
        return 0;
    case "ip":
        debug("query_host_name():" + query_host_name());
        debug("query_ip_name():" + query_ip_name());
        debug("query_ip_number():" + query_ip_number());
        debug("query_ip_port():" + query_ip_port());
        break;
    case "this_player":
        debug("this_player:" + this_player());
        break;
    case "this_interactive":
        debug("this_interactive:" + this_interactive());
        break;
    case "find_player":
        if (sizeof(args) == 2)
        {
            debug("find_player " + sprintf("Result ：%s", find_player(args[1]) + "!"));
        }
        else
        {
            debug("[Warning]参数格式：find_player 玩家id！");
        }
        break;
    case "userp":
        debug("userp : " + userp(this_object()));
        break;
    case "command":
        // command("");
        break;
    case "commands":
        debug(arg);
        print_r(me->query_commands()); // add_action()
        break;
    case "shout":
        if (sizeof(args) == 2)
        {
            shout(HIG "【系统】" + args[1] + "\n" NOR);
            debug("【系统】" + args[1]);
        }
        break;
    case "printf":
        printf("printf:\n", arg);
        printf("printf:%s\n", arg);
        break;
    /**
     * internals
     */
    case "dump_prog":
        dump_prog(me, 2, "/prog_dump");
        break;
    /**
     * mappings
     */
    case "mapping":
        // map = (["test1" : 1, "test2" : 2, 5 : "test"]);
        if (!mapp(map))
            map = ([]);
        map["test"] = ([]);
        map["test"]["test"] = 1;
        debug("map:" + map["test"]["test"]);
        if (undefinedp(map["test"]))
            map["test"] = (["key":"value"]);
        map["test"]["key2"] = "value2";
        // map["test"] = (["test" : 1]);
        // map["test"] += map;
        debug("map test:" + undefinedp(map["test"]));
        print_r(keys(map["test"]));
        print_r(values(map["test"]));
        debug("sizeof:" + sizeof(map));
        map = ([
             "spell":({"fire", "ice"}),
             "skill":({}),
               "msg":({"走过路过不要错过啦", "我是一只小小鸟"}),
            "chance":5,
        ]);
        debug_map = map;
        debug("arrayp:" + arrayp(map["skill"]));
        debug(element_of(map["msg"]));
        break;
    /**
     * mudlib
     */
    case "find_living":
        if (sizeof(args) > 1)
        {
            sscanf(arg, "%s %s", args[0], args[1]);
            debug("find_living " + sprintf("%s - %s", args[1], find_living(args[1]) + "!"));
        }
        else
        {
            debug("[Warning]参数格式：find_living id！");
        }
        break;
    case "getuid":
        debug(getuid(this_object()));
        debug(getuid());
        debug(geteuid());
        seteuid("test");
        debug(geteuid());
        debug(geteuid(previous_object()));
        // export_uid(previous_object());
        debug(geteuid(this_player()));
        break;
    case "set_light":
        if (sizeof(args) > 1)
            set_light(atoi(args[1]));
        debug("set_light = " + set_light(0));
        break;
    /**
     * numbers
     */
    case "random":
        debug("random:" + random(2));
        break;
    /**
     * objects
     */
    case "children":
        debug(arg);
        if (sizeof(args) == 2)
            print_r(filter_array(children(args[1]), (: clonep :)));
        break;
    case "all_previous_objects":
        debug(arg);
        print_r(all_previous_objects());
        break;
    case "heart_beats":
        debug(arg);
        print_r(heart_beats()); // set_heart_beat()
        break;
    case "named_livings":
        debug(arg);
        print_r(named_livings()); // set_living_name()
        break;
    case "users":
        debug(arg);
        print_r(users());
        break;
    case "livings":
        debug(arg);
        print_r(livings()); // enable_commands()
        break;
    case "objects":
        debug(arg);
        print_r(objects((: !clonep($1) :)));
        print_r(objects((: clonep :)));
        break;
    case "load_object":
        if (sizeof(args) == 2)
        {
            debug("load_object : " + load_object(args[1]));
        }
        break;
    case "find_object":
        if (sizeof(args) == 2)
        {
            debug("find_object : " + find_object(args[1]));
        }
        break;
    case "destruct":
        if (sizeof(args) == 2 && (ob = find_object(args[1])))
        {
            destruct(ob);
        }
        debug("Destruct!");
        break;
    case "present":
        if (sizeof(args) > 1)
        {
            sscanf(arg, "%s %s", args[0], args[1]);
            ob = present(args[1], env);
            if (objectp(ob))
                debug("present " + sprintf("%s - %s", args[1], ob->query("name") + "!"));
            else if (objectp(ob = present(args[1], me)))
            {
                debug("present " + sprintf("%s - %s", args[1], ob->query("name") + "!"));
            }
            else
                debug(sprintf("DEBUG：%s - %s", args[1], "在当前环境未找到!"));
        }
        else
        {
            debug("[Warning]参数格式：present id！");
        }
        break;
    case "deep_inventory":
        debug(arg);
        print_r(deep_inventory(env));
        break;
    case "all_inventory":
        debug(arg);
        print_r(all_inventory(env));
        break;
    case "first_inventory":
        debug("first_inventory：" + first_inventory(env));
        break;
    case "next_inventory":
        debug("next_inventory：" + next_inventory(me));
        break;
    case "environment":
        debug("我的位置：" + env);
        break;
    case "virtualp":
        debug("env : " + virtualp(env));
        break;
    case "file_name":
        debug("file_name:" + file_name(previous_object()));
        break;
    case "base_name":
        debug("base_name:" + base_name(previous_object()));
        break;
    case "master":
        debug("MASTER_OB:" + master());
        break;
    case "save_object":
        save_object("/debug", 01);
        break;
    case "restore_object":
        restore_object("/debug");
        debug("debug_str : " + debug_str);
        debug("debug_map : " + mapp(debug_map));
        break;
    /**
     * parsing
     */
    // process_string() - give a string with replaced calldescriptions
    case "verb":
        debug(query_verb());
        break;
    /**
     * sockets 相关测试
     */
    case "sockets":
        if (sizeof(args) == 2)
        {
            // create an efun socket
            s = socket_create(atoi(args[1]), "read_callback", "close_callback");
            debug("socket_create:" + s);
            if (s < 0)
            {
                debug("socket_create:" + socket_error(s));
            }
            else
            {
                // bind a name to a socket
                err = socket_bind(s, 3160);
                // debug("socket_bind:" + err);
                if (err < 0)
                {
                    debug("socket_bind:" + socket_error(err));
                    close_callback(s);
                }
                else
                {
                    if (args[1] != "2" && args[1] != "4")
                    {
                        // listen for connections on a socket
                        err = socket_listen(s, "listen_callback");
                        // debug("socket_listen:" + err);
                        if (err < 0)
                        {
                            debug("socket_listen:" + socket_error(err));
                            close_callback(s);
                        }
                        else
                        {
                            write("【系统提示】TCP Socket 服务已启动:" + socket_address(s, 1) + "\n");
                        }
                    }
                    else
                    {
                        write("【系统提示】UDP Socket 服务已启动:" + socket_address(s) + "\n");
                    }
                }
            }
        }
        else
        {
            debug("[Warning]参数格式：sockets 0-4!");
        }
        break;
    case "socket":
        if (sizeof(args) == 2)
        {
            // create an efun socket
            s = socket_create(atoi(args[1]), "read_callback", "close_callback");
            debug("socket_create:" + s);
            if (s < 0)
            {
                debug("socket_create:" + socket_error(s));
                close_callback(s);
            }
            else
            {
                if (args[1] != "2" && args[1] != "4")
                {
                    // TCP 模式需要先连接服务器
                    err = socket_connect(s, "118.190.104.241 3160", "read_callback", "write_callback");
                    // debug("socket_connect:" + err);
                    if (err < 0)
                    {
                        debug("socket_connect:" + socket_error(err));
                        close_callback(s);
                    }
                    else
                    {
                        write("【系统提示】TCP Socket 初始化完成！\n");
                    }
                }
                else
                {
                    write("【系统提示】UDP Socket 初始化完成！\n");
                }
            }
        }
        else
        {
            debug("[Warning]参数格式：socket 0-4!");
        }
        break;
    case "stcp":
        if (sizeof(args) > 1)
        {
            err = socket_write(s, "【socket_TCP】" + args[1] + "\n");
            if (err < 0)
            {
                debug("socket_write:" + socket_error(err));
            }
            else
            {
                write("【系统提示】消息已发送！\n");
            }
        }
        else
        {
            debug("[Warning]参数格式：stcp msg!");
        }
        break;
    case "sudp":
        if (sizeof(args) > 1)
        {
            err = socket_write(s, "【socket_UDP】" + args[1] + "\n", "118.190.104.241 3160");
            if (err < 0)
            {
                debug("socket_write:" + socket_error(err));
            }
            else
            {
                write("【系统提示】消息已发送！\n");
            }
        }
        else
        {
            debug("[Warning]参数格式：sudp msg!");
        }
        break;
    /**
     * strings
     */
    case "string":
        str = "/area/domains/town/virtual/bottom/33,100,99";
        arr = explode(str, "/");
        print_r(arr);
        i = sizeof(arr) - 1;
        debug("sscanf = " + sscanf(str, WORLD_DIR + "%*s", str));
        debug(replace_string(str, "/" + arr[i], ""));
        break;
    case "str":
        str = "abcd efg";
        debug("str:" + str);
        debug("len:" + strlen(str));
        debug("str[0..0]:" + str[0..0]);
        debug("str[0..10]:" + str[0..10]);
        debug("str[3..6]:" + str[3..6]);
        debug("str[0..<2]:" + str[0.. < 2]);
        debug("str[1..<6]:" + str[1.. < 6]);
        debug("str[1..<8]:" + str[1.. < 8]);
        break;
    /**
     * system
     */
    case "inherit_list":
        debug(arg);
        print_r(inherit_list(this_player()));
        break;
    case "deep_inherit_list":
        debug(arg);
        print_r(deep_inherit_list(this_player()));
        // printf("%@O\n", deep_inherit_list(me));
        break;
    case "all_previous_objects":
        print_r(all_previous_objects());
        break;
    case "error":
        error("强行出错！");
        break;
    /**
     * 其它测试
     */
    case "<<":
        if (sizeof(args) == 2)
        {
            debug("1<<" + args[1] + " = " + (1 << atoi(args[1])));
        }
        break;
    case "__":
        debug("魔术变量:");
        debug("__FILE__ : " + __FILE__);
        debug("__DIR__ : " + __DIR__);
        debug("__LINE__ : " + __LINE__);
        break;
    case "log_time":
        debug(log_time()); //simul_efun;
        break;
    case "gametime":
        debug(TIME_D->game_time_description());
        print_r(TIME_D->query_gametime_array());
        break;
    case "realtime":
        debug(TIME_D->real_time_description());
        print_r(TIME_D->query_realtime_array());
        break;
    case "config":
        debug("__MAX_BYTE_TRANSFER__ : " + __MAX_BYTE_TRANSFER__);
        debug("__MAX_BYTE_TRANSFER__ : " + get_config(__MAX_BYTE_TRANSFER__));
        break;
    case "emoted":
        // EMOTE_D->save();
        print_r(EMOTE_D->query_all_emote());
        print_r(EMOTE_D->query_emote("hi"));
        break;
    case "title":
        me->set_title("幸运星", time());
        break;
    case "enemy":
        print_r(me->enemy_teams());
        print_r(me->enemy_team());
        break;
    case "equip":
        debug("" + mapp(me->query_temp("equip")) &&ob = me->query_temp("equip")["weapon"]);
        debug("" + ob);
        break;
    case "team":
        if (arrayp(obs = me->query_team()))
            print_r(obs);
        else
            debug("你没有组队呢～");
        break;
    case "cd":
        me->start_condition(CD_POISON);
        me->start_condition(CD_BLESSING);
        me->start_condition(CD_BONUS_EXP);
        break;
    case "cd_clean":
        debug("clean_condition!");
        me->clean_condition();
        break;
    case "foreach":
        map = (["hp":100, "mp":"无", "sp":150]);

        foreach (string key, mixed value in map)
        {
            debug(key + " : " + value);
        }
        break;
    case "set":
        if (sizeof(args) == 3)
        {
            if (me->set(args[1], atoi(args[2])))
            {
                debug("成功。");
            }
            else
            {
                debug("失败。");
            }
        }
        break;
    case "add":
        if (sizeof(args) == 3)
        {
            if (me->add(args[1], atoi(args[2])))
            {
                debug("成功。");
            }
            else
            {
                debug("失败。");
            }
        }
        break;
    case "query":
        if (sizeof(args) == 2)
        {
            debug("结果：" + me->query(args[1]));
        }
        break;
    case "del":
        if (sizeof(args) == 2)
        {
            debug("结果：" + me->delete (args[1]));
            debug("结果：" + me->delete_spell(args[1]));
        }
        break;

    case "set_temp":
        if (sizeof(args) == 3)
        {
            if (me->set_temp(args[1], atoi(args[2])))
            {
                debug("成功。");
            }
            else
            {
                debug("失败。");
            }
        }
        break;
    case "add_temp":
        if (sizeof(args) == 3)
        {
            if (me->add_temp(args[1], atoi(args[2])))
            {
                debug("成功。");
            }
            else
            {
                debug("失败。");
            }
        }
        break;
    case "query_temp":
        if (sizeof(args) == 2)
        {
            debug("结果：" + me->query_temp(args[1]));
        }
        break;
    case "del_temp":
        if (sizeof(args) == 2)
        {
            debug("结果：" + me->delete_temp(args[1]));
        }
        break;

    case "vocation":
        if (sizeof(args) == 2)
        {
            if (VOCATION_D->change_vocation(me, args[1]))
            {
                debug("转职成功。");
            }
            else
            {
                debug("转职失败。");
            }
        }
        else if (sizeof(args) == 3)
        {
            if (find_player(args[1]) && VOCATION_D->change_vocation(find_player(args[1]), args[2]))
            {
                debug("转职成功。");
            }
            else
            {
                debug("转职失败。");
            }
        }
        else
            debug("转职请使用 vocation 职业ID，如：vocation warrior|priest|mage|martial-artist|thief");
        break;

    case "exp":
        if (sizeof(args) == 3 && ob = find_player(args[1]))
        {
            REWARD_D->bonus(ob, atoi(args[2]));
            debug(ob->name() + "的经验增加了 " + args[2] + " 点。");
        }
        else
        {
            me->set("exp", 0);
            debug("你的经验经验清零了。");
        }
        break;
    case "coin":
        me->add("coin", 1000);
        debug("你的金币增加了 1000 枚。");
        break;
    case "bonus":
        if (sizeof(args) == 3)
        {
            REWARD_D->bonus(me, atoi(args[1]), atoi(args[2]));
        }
        break;
    case "bit":
        i = 0;
        i = bitSet(i, 1);
        i = bitSet(i, 2);
        i = bitSet(i, 3);
        debug("bitSet : " + i);
        break;
    case "bitset":
        if (sizeof(args) == 3)
        {
            debug("bitSet : " + bitSet(atoi(args[1]), atoi(args[2])));
        }
        break;
    case "score":
        debug("score: " + me->query_score());
        debug("score1: " + me->query_score(1));
        debug("score2: " + me->query_score(2));
        debug("score3: " + me->query_score(3));
        break;

    case "quest":
        if (sizeof(args) == 2)
            me->delete_quest(arg[1]);
        break;

    case "bitmap":
        if (sizeof(args) == 2)
            log_file("bitmap",bitmap_font(args[1]) + "\n");
        if (sizeof(args) == 3)
            write(bitmap_font(args[1], atoi(args[2])) + "\n");
        if (sizeof(args) == 4)
            write(bitmap_font(args[1], atoi(args[2]), args[3], "  ") + "\n");
        break;

    case "level":
        if (sizeof(args) > 1)
        {
            debug("level:" + LEVEL_D->level(atoi(args[1])));
        }
        break;

    case "slice":
        debug(arg);
        if (sizeof(args) > 1)
        {
            arr = allocate(atoi(args[1]), (: $1 :));
        }
        else
        {
            arr = allocate(7, (: $1 :));
            write("arr[7]:" + undefinedp(arr[0]));
        }
        print_r(slice(arr, 0));
        print_r(slice(arr, 1));
        print_r(slice(arr, 2));
        print_r(slice(arr, 3));
        print_r(slice(arr, 4));
        break;
    default:
        debug(arg);
    }

    return 1;
}

void debug(string str)
{
    write("origin:" + origin() + "\n");
    write(RED + str + "\n" NOR);
}

void listen_callback(int fd)
{
    int s;
    debug("listen_callback:" + fd);
    // accept a connection on a socket
    s = socket_accept(fd, "read_callback", "write_callback");
    debug("socket_accept:" + s);
    if (s < 0)
    {
        debug("socket_accept:" + socket_error(s));
        close_callback(s);
    }
    else
        socket_write(s, "【socket】欢迎连接到mud.ren!^_^\n");
}

void read_callback(int fd, mixed message)
{
    debug("read_callback:" + fd);
    shout(message);
}

void write_callback(int fd)
{
    debug("write_callback:" + fd);
    socket_write(fd, "【socket】你好，这是来自客户端的问候^_^\n");
}

void close_callback(int fd)
{
    int err;
    debug("close_callback:" + fd);
    // close a socket
    err = socket_close(fd);
    // debug("socket_close:" + err);
    if (err < 0)
        debug("socket_close:" + socket_error(err));
}

int *slice(int *mob, int range)
{
    int i, slice, max, *result = ({});
    if (!range || range > 3)
        return mob;
    slice = to_int(sizeof(mob) / 3);
    max = (range < 3) ? slice * range : (sizeof(mob) - 1);
    for (i = slice * (range - 1); i <= max; i++)
    {
        result += ({mob[i]});
    }
    return result;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(origin() + "\n");
    write(@HELP
efun测试指令,请使用 debug efun_name args
HELP );
    return 1;
}
