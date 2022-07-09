/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: mysql_d.c
Description: MYSQL数据库系统守护进程
Author: xuefeng
Version: v1.0
Date: 2019-04-01
*****************************************************************************/
inherit CORE_DB;

// 调用玩家连线对象注册bbs.mud.ren网站账号
varargs void register(object ob, string host, string db, string user)
{
#ifdef __PACKAGE_DB__
    if (objectp(ob) && ob->query("id") && ob->query("password"))
    {
        mixed res;

        if (stringp(host) && stringp(db) && stringp(user))
        {
            DB::setConnection(([
                "host":host,
                "database":db,
                "user":user,
            ]));
        }

        if (DB::table("users")->where("username", ob->query("id"))->count())
        {
            return;
        }

        res = DB::table("users")->insert(([
            "username":ob->query("id"),
            "name":ob->query_temp("name"),
            "email":ob->query("id") + "_dq@mud.ren",
            "password":ob->query("password"),
            "activated_at":log_time(),
            "created_at":log_time(),
        ]));
        /* error */
        if (stringp(res))
            cecho(res);
        else
            cecho("提示：系统已自动在bbs.mud.ren注册账号，你可以使用游戏账号和密码登录社区。");
    }
#else
    cecho("注意：数据库功能被禁用，无法注册论坛账号。");
#endif
}

// 读取论坛主题
varargs void threads(int node, string host, string db, string user)
{
#ifdef __PACKAGE_DB__
    if (node)
    {
        mixed *threads;

        if (stringp(host) && stringp(db) && stringp(user))
        {
            DB::setConnection(([
                "host":host,
                "database":db,
                "user":user,
            ]));
        }
        threads = DB::table("threads")->where("node_id", node)->get("id", "title");
        {
            // todo 主题过多时分页
            mixed *res;
            write("序号" + "\t" + "主题" + "\n");
            write(repeat_string("-", 50) + "\n");
            foreach (res in threads)
            {
                write(res[0] + "\t" + res[1] + "\n");
            }
            write(repeat_string("-", 50) + "\n");
        }
    }
    else
    {
        cecho("请指定话题分类ID~");
    }
#else
    cecho("注意：数据库功能被禁用，无法读取论坛内容。");
#endif
}

// 读取论坛内容
varargs string content(int id, string host, string db, string user)
{
#ifdef __PACKAGE_DB__
    if (id)
    {
        string content;

        if (stringp(host) && stringp(db) && stringp(user))
        {
            DB::setConnection(([
                "host":host,
                "database":db,
                "user":user,
            ]));
        }
        content = DB::table("contents")->where(({({"contentable_type", "LIKE", "%Thread"}), ({"contentable_id", id})}))->value("markdown");

        return content;
    }
    else
    {
        return "请指定主题ID~";
    }
#else
    return "注意：数据库功能被禁用，无法读取论坛内容。";
#endif
}
