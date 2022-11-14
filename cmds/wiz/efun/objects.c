// 打印所有载入游戏的对象
inherit _CLEAN_UP;

int main(object me, string arg)
{
    if (arg == "-c")
        print_r(objects( (:clonep:) ));
    else if (arg == "-o")
        print_r(objects( (: !clonep($1) :) ));
    else if (arg == "-w")
    {
        print_r(objects( (: $1->is_weapon() :) ));
    }
    else if (arg == "-q")
    {
        print_r(objects((: $1->is_quester() :)));
    }
    else if (arg == "-qc")
    {
        print_r(objects((: $1->is_quester() && clonep($1) :)));
    }
    else
        print_r(objects());

    return 1;
}
