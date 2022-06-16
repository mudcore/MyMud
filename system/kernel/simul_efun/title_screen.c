/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
-----------------------------------------
 * File   : title_screen.c
 * Author : Clode@RevivalWorld
 * Date   : 2001-7-2
 * Note   : included by Simul_Efun Object
 * Update :
 *  o 2005-02-28 Clode 重新修改

-----------------------------------------
 */

#include <ansi.h>

void startup_title_screen(object me, int line)
{
    int height = me->query_temp("window_size/height");

    line += 2;

    if (line < 1)
        return;

    tell_object(me, repeat_string("\n", line) + CLR + FREEZE(line, height));

    me->set_temp("title_screen", line);
}

void spec_line_msg(object me, string msg, int line)
{
    if (line <= 0)
        return;

    tell_object(me, SAVEC + CUP(line, 1) + msg + RESTC);
    //tell_object(me, "\e[s\e["+line+";1H"+msg+"\e[u");
}

void reset_screen(object me)
{
    int line = me->query_temp("title_screen");

    while (line--)
        spec_line_msg(me, repeat_string(" ", 80), line);

    tell_object(me, RESTC SAVEC UNFR RESTC);

    me->delete_temp("title_screen");
}

varargs void clear_screen(object me, int specline)
{
    int line = me->query_temp("title_screen");
    int width = me->query_temp("window_size/width");

    if (specline)
        spec_line_msg(me, repeat_string(" ", width), specline);
    else
        while (line--)
            spec_line_msg(me, repeat_string(" ", width), line);
}
