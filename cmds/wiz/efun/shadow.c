#include <ansi.h>
inherit CLEAN_UP;

int main(object me, string arg)
{
    string str1, str2;
    object ob1, ob2, ob;
    function fun;

    if (!arg)
    {
        debug("指令格式： shadow /path/target 或者 shadow /path/ob1 on /path/ob2");
    }
    else
    {
        sscanf(arg, "%s on %s", str1, str2);

        if (str2)
        {
            if (!(ob1 = load_object(str1)))
            {
                debug("没有找到对象 " + str1);
            }
            else if (ob = environment(ob1))
            {
                debug("对象 " + str1 + " 在环境 " + file_name(ob) + " 中");
            }
            else if (ob = query_shadowing(ob1))
            {
                debug("对象 " + str1 + " 已经投影了对象 " + file_name(ob));
            }
            else if (ob = shadow(ob1, 0))
            {
                debug("对象 " + str1 + " 已经被对象 " + file_name(ob) + " 投影了");
            }
            else if (!(ob2 = load_object(str2)))
            {
                debug("没有找到对象 " + str2);
            }
            else if (ob = query_shadowing(ob2))
            {
                debug("对象 " + str2 + " 已经投影了对象 " + file_name(ob));
            }
            else
            {
                fun = bind((: shadow, ob2:), ob1);
                catch (evaluate(fun));
                debug("对象 " + str1 + " 投影 " + str2 + " 成功");
            }
        }
        else
        {
            if (!(ob1 = load_object(arg)))
            {
                debug("没有找到对象 " + arg);
            }
            else if (ob2 = query_shadowing(ob1))
            {
                debug(arg + " 投影的对象是 " + file_name(ob2));
            }
            else if (ob2 = shadow(ob1, 0))
            {
                debug("对象 " + arg + " 已经被对象 " + file_name(ob2) + " 投影了");
            }
            else
            {
                debug(arg + " 没有投影任何对象");
            }
        }
    }

    return 1;
}
