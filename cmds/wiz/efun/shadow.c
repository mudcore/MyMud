#include <ansi.h>
inherit _CLEAN_UP;

int main(object me, string arg)
{
    string str1, str2;
    object ob1, ob2, ob;
    function fun;

    if (!arg)
    {
        cecho("指令格式： shadow /path/target 或者 shadow /path/ob1 on /path/ob2");
    }
    else
    {
        sscanf(arg, "%s on %s", str1, str2);

        if (str2)
        {
            if (!(ob1 = load_object(str1)))
            {
                cecho("没有找到对象 " + str1);
            }
            else if (ob = environment(ob1))
            {
                cecho("对象 " + str1 + " 在环境 " + file_name(ob) + " 中");
            }
            else if (ob = query_shadowing(ob1))
            {
                cecho("对象 " + str1 + " 已经投影了对象 " + file_name(ob));
            }
            else if (ob = shadow(ob1, 0))
            {
                cecho("对象 " + str1 + " 已经被对象 " + file_name(ob) + " 投影了");
            }
            else if (!(ob2 = load_object(str2)))
            {
                cecho("没有找到对象 " + str2);
            }
            else if (ob = query_shadowing(ob2))
            {
                cecho("对象 " + str2 + " 已经投影了对象 " + file_name(ob));
            }
            else
            {
                fun = bind((: shadow, ob2:), ob1);
                catch (evaluate(fun));
                cecho("对象 " + str1 + " 投影 " + str2 + " 成功");
            }
        }
        else
        {
            if (!(ob1 = load_object(arg)))
            {
                cecho("没有找到对象 " + arg);
            }
            else if (ob2 = query_shadowing(ob1))
            {
                cecho(arg + " 投影的对象是 " + file_name(ob2));
            }
            else if (ob2 = shadow(ob1, 0))
            {
                cecho("对象 " + arg + " 已经被对象 " + file_name(ob2) + " 投影了");
            }
            else
            {
                cecho(arg + " 没有投影任何对象");
            }
        }
    }

    return 1;
}
