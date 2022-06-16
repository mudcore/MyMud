#include <ansi.h>

string *preload_list;
object *loginuser;

void broadcast(string msg)
{
    foreach (object ob in loginuser)
    {
        if (objectp(ob))
            tell_object(ob, msg);
    }
}

void distributed_preload()
{
    mixed err;
    object ob;

    foreach (ob in loginuser)
        if (objectp(ob))
            flush_messages(ob);

    if (!sizeof(preload_list))
    {
        foreach (ob in loginuser)
        {
            if (objectp(ob))
            {
                tell_object(ob, MUD_NAME "启动完毕，请重新连线...\n");
                destruct(ob);
            }
        }

        return;
    }

    log_file("preload", sprintf(log_time() + " 载入 %s\n", preload_list[0]));

    if (!(ob = find_object(preload_list[0])))
    {
        reset_eval_cost();

        if (err = catch (ob = load_object(preload_list[0])))
        {
            broadcast(sprintf(HIW + "%'0'3d " NOR "- 载入 %s ...", sizeof(preload_list), preload_list[0]));
            broadcast(HIR "失败\n" NOR);
            log_file("preload", sprintf("载入 %s 时发生错误: %O\n", preload_list[0], err));
        }
        else
        {
            broadcast(sprintf(HIW + "%'0'3d " NOR "- 载入 %s ...", sizeof(preload_list), preload_list[0]->short() || preload_list[0]));
            broadcast(sprintf(HIG "成功 (%.2f Kbytes)\n" NOR, memory_info(ob) / 1024.));
        }
        preload_list = preload_list[1..];
        call_out(( : distributed_preload :), 0);
    }
    else
    {
        broadcast(sprintf(HIW + "%'0'3d " NOR "- 載入 %s ...", sizeof(preload_list), preload_list[0]->query_name() || preload_list[0]));
        broadcast(sprintf(HIC "完成 (%.2f Kbytes)\n" NOR, memory_info(ob) / 1024.));
        preload_list = preload_list[1..];
        distributed_preload();
    }
}

void distributed_system_preload()
{
    string path, file;

    loginuser = allocate(0);
    preload_list = read_lines(PRELOAD);

    foreach (path in preload_list)
    {
        if (path[ < 1] == '/' && file_size(path) == -2)
        {
            foreach (file in get_dir(path))
            {
                if (file[ < 2.. < 1] == ".c" && file_size(path + file) > 0)
                    preload_list += ({path + file});
            }
            preload_list -= ({path});
        }
    }

    log_file("preload", sprintf("Preload 列表 %O\n", preload_list), 1);

    distributed_preload();
}

void create()
{
    if (uptime() < 300)
        distributed_system_preload();
}

int ready()
{
    return !preload_list || !sizeof(preload_list);
}

void add_loginuser(object ob)
{
    loginuser |= ({ob});
}
