// 列出游戏所有延迟呼叫中的 call_out()
inherit _CLEAN_UP;

int main(object me, string arg)
{
    print_r(call_out_info());

    return 1;
}
