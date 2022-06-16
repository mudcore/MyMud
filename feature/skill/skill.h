/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: skill.h 0 0
Description: 被动技能公共方法
Author: xuefeng
Version: v1.0
*****************************************************************************/
varargs mapping effect(int lv)
{
    if (lv)
    {
        if (lv > 0 && lv <= sizeof(skill_info["lv"]))
        {
            lv--;
            return skill_info["lv"][lv];
        }
        else
            return ([]);
    }
    return skill_info;
}
// 技能类型
int skill_type()
{
    return skill_info["type"];
}
// 克制魔物系列
string bonus_family()
{
    return skill_info["lv"][1]["family"];
}
