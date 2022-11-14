// passwd.c
#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    object ob;

    if (me->is_busy()) {
        return notify_fail("你现在正忙着呢。\n");
    }

    if (me->is_fighting()) {
        me->start_busy(1);
        return notify_fail("你正在战斗中，先专心把敌人解决了吧。\n");
    }

    ob = me->query_temp("login_ob");
    if (! ob)
        return notify_fail("你的人物缺少连线信息，请重新登录。\n");

    write("为了安全起见，请先输入您现在的密码：");
    input_to("get_old_pass", 1, ob);
    return 1;
}

private void get_old_pass(string pass, object ob)
{
    string old_pass;

    if (! objectp(ob))
    {
        write(RED "无法找到连接对象，取消操作。\n" NOR);
        return;
    }
    old_pass = ob->query("password");
    if (! stringp(old_pass) || (crypt(pass, old_pass) != old_pass && oldcrypt(pass, old_pass) != old_pass))
    {
        write(HIR "密码错误！\n" NOR);
        return;
    }
    write("\n请输入新的登录密码(取消修改请直接回车)：");
    input_to("get_new_pass", 1, ob);
}

private void get_new_pass(string pass, object ob)
{
    if (! objectp(ob))
    {
        write(RED "无法找到连接对象，取消操作。\n" NOR);
        return;
    }

    if (pass == "")
    {
        write("你放弃了修改密码的想法。\n");
        return;
    }

    if (strlen(pass) < 5)
    {
        write("为了账号安全，你的登录密码长度至少五位，请重新输入：");
        input_to("get_new_pass", 1, ob);
        return;
    }

    write("\n请再输入一次新的登录密码：");
    input_to("confirm_new_pass", 1, ob, crypt(pass, 0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
    object me;
    if (! objectp(ob))
    {
        write(RED "无法找到连接对象，取消操作。\n" NOR);
        return;
    }

    write("\n");
    if (crypt(pass, new_pass) != new_pass)
    {
        write("对不起，您两次输入的并不相同，请重新输入你的登录密码：");
        input_to("get_new_pass", 1, ob);
        return;
    }

    if (! ob->set("password", new_pass))
    {
        write(HIR "登录密码变更失败！\n" NOR);
        return;
    }

    ob->save();
    me = this_player();
    assure_file(LOG_DIR + "static/passwd");
    log_file("static/passwd", sprintf("%s - %s修改了登录密码 (%s)\n",
              log_time(), this_player()->short(),
              interactive(me) ? query_ip_name(me) : 0));
    write(HIG "登录密码变更成功。\n" NOR);
}

int help()
{
    write(@HELP
指令格式 : passwd

这个指令可以修改你的登录密码。

HELP );
    return 1;
}
