inherit _CLEAN_UP;

int main(object me, string arg)
{
    string *setting_list = ({
        "brief", // 简要信息显示
    });
    mapping settings = me->query("settings");

    if (me->is_busy()) {
        return notify_fail("你现在正忙着呢。\n");
    }

    if (me->is_fighting()) {
        me->start_busy(1);
        return notify_fail("你正在战斗中，先专心把敌人解决了吧。\n");
    }
    if (!arg)
    {
        if(mapp(settings))
        {
            cecho("你的环境变量设置如下：");
            foreach(string setting, int value in settings)
            {
                printf("%-10s = %d\n", setting, value);
            }
        }
        else
            return notify_fail("你还没有设置任何环境变量。\n");
    }
    else if (arg && member_array(arg, setting_list) >= 0)
    {
        me->set("settings/" + arg, 1);
        cecho("已设置完成。");
    }
    else if (sscanf(arg, "%s -d", arg) || sscanf(arg, "-d %s", arg))
    {
        me->set("settings/" + arg, 0);
        cecho("已取消设置。");
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 :
    set         显示个人环境参数列表
    set arg     设置 arg 环境参数
    set -d arg  取消 arg 环境参数

这个指令可以让你设置自己的游戏参数。

目前可设置参数如下：

    brief   简要战斗信息显示

HELP );
    return 1;
}
