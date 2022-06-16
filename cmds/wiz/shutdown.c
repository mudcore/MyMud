#include <ansi.h>

int main(object me, string arg)
{
    int i;
    object login_ob, *user = users();
    if (wizardp(me))
    {
        write(HIR "[" + this_object() + "]->main()!\n" NOR);
        for (i = 0; i < sizeof(user); i++)
        {
            user[i]->set("last_saved_at", time());
            catch (user[i]->save_inventory());
            catch (user[i]->save_depot());
            catch (user[i]->save());
            user[i]->set_temp("block_msg/all", 1);
            login_ob = user[i]->query_temp("login_ob");
            if (objectp(login_ob))
                catch (login_ob->save());
        }
        if (find_object(DBASE_D))
            catch (DBASE_D->mud_shutdown());

        shutdown(0);
        return 1;
    }
    else
    {
        return 0;
    }
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : shutdown

服务器 shutdown 指令。

HELP );
    return 1;
}
