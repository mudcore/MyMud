/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_title.c
Description: 玩家称号继承接口
Author: xuefeng
Version: v1.0
Date: 2019-04-01
History:
*****************************************************************************/
mapping titles;

// 设置称号及获取时间
void set_title(string title, int time)
{
    if (!mapp(titles))
        titles = ([title:time]);
    else
        titles[title] = time;
}

int query_title(string title)
{
    if (mapp(titles) && !undefinedp(titles[title]))
        return titles[title];
    return 0;
}

mapping query_titles() { return titles; }
