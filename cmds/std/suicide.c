// suicide.c

#include <ansi.h>

inherit _CLEAN_UP;

private int slow_suicide(object me);
private int halt_suicide(object me);
string remove_user(object ob);

int main(object me, string arg)
{
    if (me->is_busy())
        return notify_fail("你上一个动作还没完成。\n");

    if (! arg || arg != "-f")
        return notify_fail(HIC "您选择永远死掉的自杀方式，这个人物的资"
                               "料将永远删除，请务必\n考虑清楚，确定的话请"
                               "输入完整的自杀(" HIY "suicide -f" HIC ")指"
                               "令。\n\n" NOR);

    write(HIR "您选择永远死掉的自杀方式，这个人物的资料将永远删除，请务必\n"
              "考虑清楚，确定的话请输入您的登录密码：\n" NOR);
    input_to("check_password", 1, me);
    return 1;
}

private void check_password(string passwd, object me)
{
    object login_ob;
    string old_pass;

    login_ob = me->query_temp("login_ob");
    old_pass = login_ob->query("password");

    if (! stringp(old_pass) || crypt(passwd, old_pass) != old_pass)
    {
        write(HIW "\n密码错误。\n");
        return;
    }

    tell_object(me, HIR "\n你决定要自杀了，如果十五秒"
                        "内不后悔(" HIC "halt停止" HIR ")，就"
                        "真的永别了。\n\n" NOR);
    me->set_temp("suicide/time", time());
    me->set_temp("suicide/last", 0);
    me->set_temp("suicide/from", query_ip_number(me));
    me->start_busy((: slow_suicide, me :), (: halt_suicide, me :));

}

private int slow_suicide(object me)
{
    object login_ob;
    int t;

    if (! objectp(me))
        return 0;

    t = time() - me->query_temp("suicide/time");
    if (t < me->query_temp("suicide/last"))
    {
        me->delete_temp("suicide");
        return 0;
    }

    if (t < 15)
    {
        if (t - me->query_temp("suicide/last") < 5)
            return 1;

        tell_object(me, HIR "\n你还有" + (15 - t) +
                    "秒钟仔细考虑(" HIC "halt停止" HIR ")。\n" NOR);
        me->set_temp("suicide/last", t / 5 * 5);
        return 1;
    }

    login_ob = me->query_temp("login_ob");
    if (! login_ob || ! interactive(me)) return 0;

    write(HIW "\n既然如此…那就……永别了，" + me->name() + "。\n"
              HIC "欢迎您能够以新的身份再次光临「" HIY MUD_NAME
              HIC "」。\n\n" NOR);

    if (me->query("lv") > 9)
    {
        CHANNEL_D->do_channel(this_object(), "rumor",
                              sprintf("%s自杀了，以后你再也看"
                              "不到这个人了。", me->name()));

        log_file("static/suicide", sprintf("[%s]用户%s自杀档案(%s)。\n",
                 log_time(), me->short(), me->query_temp("suicide/from")));
    }

    remove_user(me);
    return 0;
}

private int halt_suicide(object me)
{
    tell_object(me, HIG "你打消了寻死的念头。\n" NOR);
    me->delete_temp("suicide");
    return 1;
}

string remove_user(object ob)
{
    string id = ob->query("id");
    // 删除数据库缓存
    if (env("CACHE_DATA"))
    {
        CACHE_D->delete(ob);
    }
    if (ob->query_temp("login_ob"))
        catch(destruct(ob->query_temp("login_ob")));
    catch(destruct(ob));

    // todo : clear the data of user first

    // remove the file of the user
    rm(DATA_DIR + "login/" + id + __SAVE_EXTENSION__);
    rm(DATA_DIR + "user/" + id + __SAVE_EXTENSION__);
}

int help ()
{
    write(@HELP
指令格式: suicide [-f]

如果因为某种原因你不想活了，你可以选择自杀。
suicide -f : 永远的除去玩家资料，系统会要求你
             输入密码以确认身份。

HELP);
    return 1;
}
