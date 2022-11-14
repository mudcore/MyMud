inherit _CLEAN_UP;

int main(object me, string arg)
{
    object *list = filter_array(children(USER_OB), (: clonep :));
    int j;
    if (!arg)
    {
        printf("\n%-23s%|9s%|13s%5s%|21s%|9s\n", "玩家", "职业", "称号", "等级", "位置", "状态");
        printf("-------------------------------------------------------------------------------\n");
        for (j = 0; j < sizeof(list); j++)
        {
            if (list[j]->query("name"))
                printf("%-23s%|9s%|13s%5d%|21s%|9s\n",
                    list[j]->short(),
                    chinese(list[j]->query("vocation")),
                    list[j]->query("title"),
                    list[j]->query("lv"),
                    remove_ansi(environment(list[j])->short()||environment(list[j])->query("name")),
                    (list[j]->query_temp("net_dead") ?
                    "#断线#" : (query_idle(list[j]) > 60 ?
                    "*发呆*" : (in_input(list[j]) ?
                    "[输入中]" : (in_edit(list[j]) ?
                    "[编辑中]" : "")))));
        }
        printf("-------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n%-23s%|9s%|13s%5s\n", "玩家", "职业", "称号", "等级");
        printf("-----------------------------------------------------\n");
        for (j = 0; j < sizeof(list); j++)
        {
            if (list[j]->query("name"))
                printf("%-23s%|9s%|13s%5d\n",
                    list[j]->short(),
                    chinese(list[j]->query("vocation")),
                    list[j]->query("title"),
                    list[j]->query("lv"));
        }
        write("-----------------------------------------------------\n");
        // write(" 提示：输入 who -l 查看在线玩家更多资料。\n");
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : who

这个指令可以查看在线玩家列表。

HELP );
    return 1;
}
