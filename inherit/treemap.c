/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: treemap.c
Description: mapping数据设置接口
Author: xuefeng
Version: v1.0
Date: 2019-05-05
*****************************************************************************/

nomask mixed _query(mapping map, string *parts)
{
    mixed value;
    int i, s;

    value = map;
    s = sizeof(parts);
    for (i = 0; i < s; i++)
    {
        if (undefinedp(value = value[parts[i]]))
            break;
        if (!mapp(value))
            break;
    }
    return value;
}

nomask int _delete(mapping map, string *parts)
{
    if (sizeof(parts) == 1)
    {
        map_delete(map, parts[0]);
        return 1;
    }
    if (!map[parts[0]] || !mapp(map[parts[0]]))
        return 0;
    return _delete(map[parts[0]], parts[1..sizeof(parts)-1]);
}

nomask mixed _set(mapping map, string *parts, mixed value)
{
    if (sizeof(parts) == 1)
        return map[parts[0]] = value;

    if (!map[parts[0]] || !mapp(map[parts[0]]))
        map[parts[0]] = ([parts[1]:0]);

    return _set(map[parts[0]], parts[1..sizeof(parts)-1], value);
}
