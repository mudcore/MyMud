int main(object me, string arg)
{
    if (arg)
    {
        me->more(sort_string(MYSQL_D->content(atoi(arg))));
    }
    else
    {
        MYSQL_D->threads(config("MUDREN_NODE"));
        cecho("请使用`bbs 序号`查看指定主题内容！\n提示：你也可以输入非列表中的序号查看bbs.mud.ren的内容。");
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : bbs [id]

这个指令可以让你查看mudRen论坛上的主题。

HELP );
    return 1;
}
