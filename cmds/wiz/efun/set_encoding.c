// 设置当前玩家encoding
inherit _CLEAN_UP;

int main(object me, string arg)
{
    if (arg)
    {
        set_encoding(arg);
    }

    printf("query_encoding : %s\n", query_encoding());

    return 1;
}
