int main(object me, string arg)
{
    if (arg)
    {
        color_cat(CONFIG_DIR + arg);
    }
    else
    {
        color_cat(MOTD);
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : motd <motd>

这个指令可以让你查看欢迎界面。
HELP );
    return 1;
}
