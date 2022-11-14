inherit _CLEAN_UP;

int main(object me, string arg)
{
    string mob_desc;
    if (!wizardp(me))
        return 0;

    if (!arg || arg == "-d" || arg == "-e")
        return notify_fail("指令格式 : mob [-d|-e] <id>\n");

    if (sscanf(arg, "-d %s", arg))
    {
        write("删除怪物 " + arg + " 的描述。\n");
        return MONSTER_D->delete_desc(arg);
    }

    if (sscanf(arg, "-e %s", arg))
    {
        for (int i = 0; i < strlen(arg); i++)
            if ((arg[i] <'a' && arg[i] != 32) || arg[i] > 'z')
                return notify_fail("魔物名称必须由小写字母和空格组成\n");

        write("编辑魔物" + arg + "的描述，请输入：\n");
        input_to("get_mob_desc", arg);
        return 1;
    }

    if (mob_desc = MONSTER_D->desc(arg, 1))
    {
        write(mob_desc + "\n");
    }
    else
    {
        cecho("系统还没有记录这个魔物呢。");
    }
    return 1;
}

varargs int get_mob_desc(string msg, string id)
{
    msg = replace_string(msg, "\\n", "\n");
    if (msg == "x")
    {
        write("你取消了编辑。\n");
        return 1;
    }
    write("添加完成!\n");
    MONSTER_D->set_desc(id, msg);
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : mob [-d|-e] <id>

这个指令可以修改，删除魔物的描述或列出其内容。 加上 -d 参数会删
除指定的魔物，-e 参数则会编辑指定魔物的内容.

一个魔物讯息可以有很多行, 在空白行输入 '.' 表示结束输入该
项.

HELP );
    return 1;
}
