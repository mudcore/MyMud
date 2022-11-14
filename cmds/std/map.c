#include <ansi.h>
inherit _CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    object env = environment(me);
    int area = env->query("area");
    string map = HELP_DIR "map/" + area + ".map";
    if (!arg)
    {
        if (env->is_area())
        {
            map = base_name(env)+".ansi";
        }
        if (file_size(map) > 0)
        {
            me->more_file(map);
            return 1;
        }
        else
        {
            return notify_fail("当前地区没有可用地图。\n");
        }
    }
    else if (arg == "-a")
    {
        if (!me->query("worldmap"))
            return notify_fail("你还没有获得世界地图。\n");

        me->more_file(HELP_DIR "map/world.map");
    }
    else if (arg == "here")
    {
        map = HELP_DIR "map/city/" + area + ".map";
        if (env->query("maze_room"))
        {
            int *maze_room = me->query_temp("maze") || ({});
            if (member_array(area, maze_room) > -1)
            {
                int n = strsrch(base_name(env), "/", -1);
                map = base_name(env)[0..n-1]+".map";
            }
        }
        if (env->is_area())
        {
            map = base_name(env)+".ansi";
        }

        if (file_size(map) > 0)
        {
            me->more_file(map);
            return 1;
        }
        else
        {
            return notify_fail("当前地区没有可用地图。\n");
        }
    }
    else
    {
        help(me);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : map          查看当前地区地图
           map here     查看所在城市或村庄地图
           map [-a]     查看世界地图

这个指令可以查看当前区域地图或世界地图。

HELP );
    return 1;
}
