/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_vocation.c
Description: 转职记录继承接口
Author: xuefeng
Version: v1.0
Date: 2019-03-24
History:
*****************************************************************************/
mapping vocation_info;

mapping query_vocation_list() { return vocation_info; }

// 设置职业信息记录
void set_vocation_info(string vocation, string key, int value)
{
    if (!mapp(vocation_info))
        vocation_info = ([]);
    if (undefinedp(vocation_info[vocation]))
        vocation_info[vocation] = ([key:value]);
    else
        vocation_info[vocation][key] = value;
}

// 查询职业信息记录
mapping query_vocation_info(string vocation)
{
    if (mapp(vocation_info) && !undefinedp(vocation_info[vocation]))
        return vocation_info[vocation];
    return 0;
}
