// 生物特征模块
inherit CORE_LIVING;
inherit _ATTRIBUTE;
inherit _HEART_BEAT;

void create()
{
    seteuid(0); // export_uid
}

// 判断是否是有生命的，包括 disable_living 的角色
int is_character() { return 1; }

// 角色激活
void setup()
{
    seteuid(getuid(this_object()));
    set_heart_beat(1);
    enable_living(); // COMMAND 中定义的生物激活方法
#ifdef CHAR_D
    CHAR_D->setup(this_object());
#endif
}

// 从游戏中移除这个生物
void remove()
{
    destruct(this_object());
}
