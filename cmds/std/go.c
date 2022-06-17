/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: go.c
Description: 标准移动指令
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
#include <ansi.h>
#include <type.h>

int do_area_move(object me, object env, string dir);
int do_room_move(object me, object env, string dir);

nosave mapping default_dirs = ([
        "north":"北方",
        "south":"南方",
         "east":"东方",
         "west":"西方",
      "northup":"北边",
      "southup":"南边",
       "eastup":"东边",
       "westup":"西边",
    "northdown":"北边",
    "southdown":"南边",
     "eastdown":"东边",
     "westdown":"西边",
    "northeast":"东北",
    "northwest":"西北",
    "southeast":"东南",
    "southwest":"西南",
           "up":"上面",
         "down":"下面",
        "enter":"里面",
          "out":"外面",
]);

nosave mapping r_dirs = ([
        "north":"south",
        "south":"north",
         "east":"west",
         "west":"east",
      "northup":"southdown",
      "southup":"northdown",
       "eastup":"westdown",
       "westup":"eastdown",
    "northdown":"southup",
    "southdown":"northup",
     "eastdown":"westup",
     "westdown":"eastup",
    "northeast":"southwest",
    "northwest":"southeast",
    "southeast":"northwest",
    "southwest":"northeast",
           "up":"down",
         "down":"up",
        "enter":"out",
          "out":"enter",
]);

nosave mapping empty_mapping = ([]);

int main(object me, string arg)
{
    object env;

    if (!arg)
        return notify_fail("你要往哪个方向走？\n");

    if (!objectp(me))
        return 1;

    env = environment(me);
    if (!env)
        return notify_fail("你哪里也去不了。\n");

    if (env->is_area())
        return do_area_move(me, env, arg);
    else
        return do_room_move(me, env, arg);
}

int do_room_move(object me, object env, string arg)
{
    string dir, msg_in, msg_out;
    object obj, *enemies = ({});
    mapping exit;
    mixed dest;
    int result;

    if (!mapp(exit = env->query("exits")) || undefinedp(exit[arg]))
    {
        if (query_verb() == "go")
            return notify_fail("这个方向没有出路。\n");
    }

    if (me->is_busy())
    {
        switch (random(5))
        {
        case 0:
            return notify_fail("你上一个动作还么完成 ○RZ\n");
        case 1:
            return notify_fail("你正忙着呢(°ー°〃)\n");
        case 2:
            return notify_fail("你停下来长长的缓了一口气 (′Д`)彡\n");
        default:
            return notify_fail("你擦了擦汗（─.─||）\n");
        }
    }

    dest = exit[arg];

    switch (typeof(dest))
    {
    case T_OBJECT:
        obj = dest;
        break;
    case T_STRING:
        if (!objectp(obj = load_object(dest)))
        {
            return notify_fail(sprintf("目标环境异常，无法向 %s 移动。\n", dest));
        }
        break;
    case T_MAPPING:
        if (undefinedp(dest["filename"]) || undefinedp(dest["x_axis"]) || undefinedp(dest["y_axis"]))
        {
            return notify_fail(sprintf("目标方向异常，无法向 %s 移动。\n", arg));
        }
        if (!objectp(obj = load_object(dest["filename"])))
        {
            return notify_fail(sprintf("目标环境异常，无法向 %s 移动。\n", dest["filename"]));
        }
        break;
    // case T_INT:
    // case T_FLOAT:
    // case T_ARRAY:
    default:
        return notify_fail("这个方向的出口有问题，请联系巫师处理。\n");
    }

    if (!undefinedp(default_dirs[arg]))
        dir = default_dirs[arg];

    if (me->is_fighting())
    {
        me->clean_up_enemy();
        enemies = me->query_enemy();
    }

    if (sizeof(enemies))
    {
        if (random(100) > random(me->query_luk()))
        {
            msg("warning", "$ME想逃跑结果被$YOU拦住了。", me, element_of(enemies));
            me->start_busy(1);
            return notify_fail("你逃跑失败了... T_T\n");
        }
        else
        {
            msg("combat", "$ME成功的逃跑了···", me);
        }
    }

    // 特殊方向限制移动
    result = env->valid_leave(me, arg);
    // debug_message("valid_leave:" + result);
    if (!result)
        return 1;

    msg_out = me->query("name") + "往" + dir + "离开了。";
    message("vision", msg_out, environment(me), ({me}));
    msg_in = me->query("name") + "走了过来。";
    // move I to dest
    if (obj->is_area())
    {
        if (area_move(obj, me, dest["x_axis"], dest["y_axis"]))
        {
            object *obs;
            obs = obj->query_inventory(dest["x_axis"], dest["y_axis"]);
            tell_area(obj, dest["x_axis"], dest["y_axis"], msg_in, ({me}));
            // 對進入的座標做init()動作
            if (sizeof(obs))
                obs->init();
        }
        else
            return notify_fail("移动失败！！\n");
    }
    else if (!me->move(obj))
        return notify_fail("移动失败！\n");
    else
        message("vision", msg_in, environment(me), ({me}));
    // 因为移动到目标环境后可能被destruct，需判断me还在不在
    if (!objectp(me))
        return 1;

    if (!random(me->query_agi())) // 组队时可能掉队哦　^_^
        me->start_busy(random(1));

    // 让队友自动跟随
    if (environment(me) != env)
    {
        all_inventory(env)->follow_me(me, arg);
    }
    return 1;
}


int do_area_move(object me, object env, string dir)
{
    int x, y;
    string *area_exits, dir_name, min, mout;
    object new_env, *obs;
    mapping info;

    if (!(info = me->query("area_info")))
        return 0;

    x = info["x_axis"];
    y = info["y_axis"];

    area_exits = env->query_exits(x, y);

    if (dir == "escape")
    {
        if (!sizeof(area_exits))
        {
            write("你已經無路可逃了！\n");
            return 1;
        }
        else
            dir = element_of(area_exits);
    }

    if (member_array(dir, area_exits) == -1)
    {
        write("這個方向沒有出路。\n");
        return 1;
    }

    if (undefinedp(dir_name = default_dirs[dir]))
        dir_name = dir;

    if (me->is_fighting())
    {
        object *enemies;
        me->clean_up_enemy();
        enemies = me->query_enemy();

        if (sizeof(enemies))
        {
            if (random(100) > random(me->query_luk()))
            {
                msg("warning", "$ME想逃跑结果被$YOU拦住了。", me, element_of(enemies));
                me->start_busy(1);
                return notify_fail("你逃跑失败了... T_T\n");
            }
            else
            {
                msg("combat", "$ME成功的逃跑了···", me);
            }
        }
    }

    // 通过moveObject实现移动
    if (!env->moveObject(me, dir))
        return 1;

    new_env = environment(me);

    if (undefinedp(dir_name = default_dirs[dir]))
        dir_name = dir;

    if (me->is_fighting())
    {
        mout = "往" + dir_name + "落荒而逃了。\n";
        min = "跌跌撞撞地跑了過來﹐模樣有些狼狽。\n";
    }
    else
    {
        mout = "往" + dir_name + "離開。\n";
        min = "走了過來。\n";
    }

    // 顯示離開訊息
    tell_area(env, x, y, me->name() + mout, ({me}));

    if (new_env->is_area())
    {
        // 顯示進入訊息
        tell_area(new_env, info["x_axis"], info["y_axis"], me->name() + min, ({me}));

        // 對進入的座標做init()動作
        obs = new_env->query_inventory(info["x_axis"], info["y_axis"]);
        // 本质上还在一个环境中，需要主动调用init()
        if (sizeof(obs) > 1)
            obs->init();
    }
    else
        tell_room(new_env, me->name() + min, me);

    // 讓移動性的設定歸零(如sneak)
    me->set_temp("pending", 0);

    // 是否有人物跟隨
    obs = env->query_inventory(x, y);
    obs->follow_me(me, dir);

    return 1;
}

string query_reverse(string dir)
{
    if (undefinedp(r_dirs[dir]))
        return 0;
    return r_dirs[dir];
}

string query_chinese_dir(string dir)
{
    return default_dirs[dir];
}

int help(object me)
{
    write(@HELP
指令格式 : go [方向]

这个指令可以让你向指定的方向移动。

HELP );
    return 1;
}
