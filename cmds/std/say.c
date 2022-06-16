int main(object me, string arg)
{
    string msg;
    arg = arg ? arg : "...";
    msg = "$ME说到：" + arg;
    // write("你说到：" +  arg + "\n");
    // say(HIC + me->query("name") + "说到：" +  arg + "\n" NOR);
    msg("say", msg, me);
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : say [内容]

这个指令可以让你和房间里的其他玩家聊天。

HELP );
    return 1;
}
