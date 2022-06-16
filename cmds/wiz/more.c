// 查看源文件
int main(object me, string arg)
{
    if (!wizardp(me))
        return 0;

    if (!arg)
        return notify_fail("指令格式 : more <档案名>\n");
    if (arg == "here")
    {
        arg = base_name(environment(me));
    }
    sscanf(arg, "%s.c", arg);
    arg = arg + ".c";
    arg = resolve_path(me->query("cwd"), arg);
    // todo 虚拟对象代码
    if (file_size(arg) < 0)
    {
        return notify_fail("没有找到这个档案 T_T\n");
    }

    me->more_file(arg);

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : more <文档>

这个指令可以查看指定 .c 文档的源代码。
HELP );
    return 1;
}
