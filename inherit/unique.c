/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: unique.c
Description: 独一无二的对象继承接口
Author: xuefeng
Version: v1.0
Date: 2019-03-17
History:
*****************************************************************************/
int is_unique() { return 1; }

object check_clone()
{
    object me;

    me = this_object();
    if (clonep(me))
    {
        destruct(me);
        return 0;
    }

    if (!stringp(me->query("home")))
        return this_object();

    me->move(me->query("home"));
    if (me->is_character())
    {
        message("vision", me->name() + "走了过来。\n", environment(me));
    }
    return this_object();
}
