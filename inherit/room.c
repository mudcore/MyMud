/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: room.c
Description: 通用游戏环境设置接口，通过reset()自动加载物品对象到房间
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
inherit CORE_ROOM;

// void create(){}

// ENABLE_OPTIMIZE
nosave string long;
nosave string short;

mixed set(mixed idx, mixed data)
{
    switch (idx)
    {
    case "short":
        return short = data;
    case "long":
        return long = data;
    default:
        return ::set(idx, data);
    }
}

varargs mixed query(mixed idx, int raw)
{
    switch (idx)
    {
    case "short":
        return short;
    case "long":
        return long;
    default:
        return ::query(idx, raw);
    }
}

void delete(mixed idx)
{
    switch (idx)
    {
    case "short":
        short = 0;
        break;
    case "long":
        long = 0;
        break;
    default:
        ::delete (idx);
        break;
    }
}

string short()
{
    return short;
}

string long()
{
    return long;
}

// 设置环境区域怪物种类、每种数量上限、等级范围(0~7)
varargs void setMob(int mob, int max, int range)
{
    set("mob", mob);
    set("mob_max", max);
    set("mob_range", range);
}
