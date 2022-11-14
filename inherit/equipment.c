/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: equipment.c
Description: 装备物品公共接口
Author: xuefeng
Version: v1.0
Date: 2019-03-14
History:
*****************************************************************************/
inherit _ITEM;

int is_equipment() { return 1; }

int equip()
{
    object owner;
    mapping equip_info, equip_effect;
    string *status, gender;

    owner = environment();
    if (!owner || !owner->is_character())
        return 0;

    if (query_temp("equipped"))
    {
        return notify_fail("你已经装备着呢。\n");
    }

    if (!mapp(equip_info = query("equip_info")))
        return notify_fail("你无法装备这件物品。\n");

    if (arrayp(equip_info["vocation"]) && sizeof(equip_info["vocation"]) &&
         member_array(owner->query("vocation"), equip_info["vocation"]) == -1)
    {
        if ((equip_info["type"] == "weapon") && bitCheck(owner->query_skill(equip_info["weapon"]), 10))
        {
            ; // 可以装备
        }
        else if ((equip_info["type"] == "shield") && bitCheck(owner->query_skill("shield"), 10))
        {
            ; // 可以装备
        }
        else
            return notify_fail("你无法装备这件装备。\n");
    }

    if (owner->query_temp("equip/" + equip_info["type"]))
    {
        return notify_fail("你已经装备了同类型的装备啦。\n");
    }
    if (equip_info["lv"] > owner->query("lv"))
    {
        return notify_fail("你的等级不足以装备这件物品。\n");
    }
    if (equip_info["gender"] && owner->query("vocation") != "minstrel")
    {
        if (equip_info["gender"] == 1)
        {
            gender = "男性";
        }
        else
        {
            gender = "女性";
        }
        if (gender != owner->query("gender"))
        {
            return notify_fail("你的性别无法装备这件物品。\n");
        }
    }

    owner->set_temp("equip/" + equip_info["type"], this_object());
    equip_effect = query("equip_effect");
    status = keys(equip_effect);
    // 增加装备属性效果
    for (int i = 0; i < sizeof(status); i++)
        owner->add_temp("buff/attr/" + status[i], equip_effect[status[i]]);
    // 激发装备被动技能
    if (equip_info["weapon"])
    {
        owner->skill_effect(equip_info["weapon"], 1);
        owner->skill_effect("fist", 0);
    }
    else if (equip_info["type"] == "shield")
        owner->skill_effect("shield", 1);

    set_temp("equipped", 1);
    delete_temp("equip");
    return 1;
}

int unequip()
{
    object owner;
    mapping equip_info, equip_effect, owner_status;
    string *status;
    int equipped;

    owner = environment();
    if (!owner || !owner->is_character())
        return 0;

    if (!(equipped = query_temp("equipped")))
        return notify_fail("你目前并没有装备这样东西。\n");

    equip_info = query("equip_info");
    equip_effect = query("equip_effect");

    if (equipped)
    {
        owner->delete_temp("equip/" + equip_info["type"]);
        if (equip_info["weapon"])
        {
            owner->skill_effect(equip_info["weapon"], 0);
            owner->skill_effect("fist", 1);
        }
        else if (equip_info["type"] == "shield")
            owner->skill_effect("shield", 0);
    }

    if (mapp(equip_effect))
    {
        status = keys(equip_effect);
        owner_status = owner->query_temp("buff/attr");
        for (int i = 0; i < sizeof(status); i++)
            owner_status[status[i]] -= equip_effect[status[i]];
    }

    delete_temp("equipped");
    return 1;
}

// 装备前缀词（装备增加前缀效果）
void prefix()
{
    // todo
}

// 套装
void suit()
{
    // todo
}
