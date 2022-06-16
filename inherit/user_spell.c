/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: user_spell.c
Description: 玩家角色魔法咒文继承接口
Author: xuefeng
Version: v1.0
Date: 2019-03-24
History:
*****************************************************************************/
mapping spells;

void set_spell(string spell, int val)
{
    if (!find_object(F_SPELL(spell)) &&
        file_size(F_SPELL(spell) + ".c") < 0)
        error("F_SPELL: No such spell (" + spell + ")\n");

    if (!mapp(spells))
        spells = ([spell:val]);
    else
        spells[spell] = val;
}

// 清除咒文
int delete_spell(string spell)
{
    if (mapp(spells))
    {
        map_delete(spells, spell);
        return undefinedp(spells[spell]);
    }
    return 0;
}
// 清除所有咒文
void delete_spells()
{
    spells = ([]);
}

int query_spell(string spell)
{
    if (mapp(spells) && !undefinedp(spells[spell]))
        return spells[spell];
    return 0;
}

mapping query_spells() { return spells; }
