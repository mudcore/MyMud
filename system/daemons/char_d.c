/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: char_d.c
Description: 角色系统守护进程 CHAR_D
Author: xuefeng
Version: v1.0
Date: 2019-03-12
History:
*****************************************************************************/
// 初始化玩家角色
void init_player(object user)
{
    user->set("birthday", time());
    user->set("title", "初心者");
    user->set("vocation", "common");
    user->set("exp", 0); // 经验
    user->set("lv", 1);  // 等级
    user->set_attr("str", 6);     // 力量
    user->set_attr("agi", 6);     // 速度
    user->set_attr("vit", 6);     // 耐力
    user->set_attr("luk", 3);     // 幸运
    user->set_attr("charm", 3);   // 幸运
    user->set_attr("mend", 0);    // 恢复魔力
    user->set_attr("int", 0);     // 攻击魔力
    user->set_attr("max_hp", 14); // 最大ＨＰ
    user->set_attr("max_mp", 0);  // 最大ＭＰ
    user->set_attr("sp", 0);      // 技能点
    user->set_attr("hp", 14);     // 当前ＨＰ
    user->set_attr("mp", 0);      // 当前ＭＰ
}

void setup(object ob)
{
    string race;
    mapping my;

    if (!stringp(race = ob->query("race")))
    {
        race = "人类";
        ob->set("race", race);
    }

    my = ob->query_entire_dbase();

    switch(race)
    {
        case "人类":
            if (undefinedp(my["attr"])){
                init_player(ob);
            }
            break;
        case "魔物":
            if (undefinedp(my["attr"])){
                ob->set_attr("str", 15); // 力量
                ob->set_attr("agi", 8); // 速度
                ob->set_attr("vit", 7); // 耐力
                ob->set_attr("max_hp", 20); // 最大ＨＰ
                ob->set_attr("max_mp", 0); // 最大ＭＰ
                ob->set_attr("hp", 20); // 当前ＨＰ
                ob->set_attr("mp", 0); // 当前ＭＰ
            }
            if(my["attr"]["hp"] < my["attr"]["max_hp"])
                my["attr"]["hp"] = my["attr"]["max_hp"];
            if(my["attr"]["mp"] < my["attr"]["max_mp"])
                my["attr"]["mp"] = my["attr"]["max_mp"];
            break;
        case "野兽":
            // BEAST_RACE->setup(ob);
            break;
        default:
            debug_message("CHAR_D: undefined race " + race + ".\n");
    }

    if(undefinedp(my["attr"]["hp"]) || my["attr"]["hp"] > my["attr"]["max_hp"])
        my["attr"]["hp"] = my["attr"]["max_hp"];
    if(undefinedp(my["attr"]["mp"]) || my["attr"]["mp"] > my["attr"]["max_mp"])
        my["attr"]["mp"] = my["attr"]["max_mp"];
}
