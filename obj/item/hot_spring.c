#include <ansi.h>

inherit STD_ITEM;

private void create()
{
    ::create();
    set_name("温泉", ({"hot spring", "spring"}));
    set("long", HIC "这是个大大的温泉，散发着淡淡的魔力，泡（bath）在里面可以缓解疲劳。" NOR);
    set("no_get", "这种事情只有女神才能办到吧 T_T\n");
}

void init()
{
    add_action("do_bath", "bath");
}

int do_bath(string arg)
{
    string msg;
    object me = this_player();

    me->set_attr("hp", me->query_max_hp());
    me->set_attr("mp", me->query_max_mp());
    msg = "$ME泡在温泉里美美的睡了一觉。";
    msg("vision", msg, me);
    me->start_busy(5 + random(5));

    return 1;
}
