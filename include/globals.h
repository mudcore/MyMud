// 全局包含文件

#define HTTP_PORT    8080

#define ROOT_UID      "Root"
#define BACKBONE_UID  "Backbone"

#define WORLD_DIR     "/world/"
#define WORLD_8_DIR    "/world/dq8/"
#define WORLD_9_DIR    "/world/dq9/"
#define CMD_DIR       "/cmds/"
#define CONFIG_DIR    "/system/etc/"
#define DATA_DIR      "/data/"
#define HELP_DIR      "/help/"
#define LOG_DIR       "/log/"
#define SINGLE_DIR    "/system/kernel/"
#define ITEM_DIR      "/obj/item/"
#define MOB_DIR       "/obj/mob/"
#define EQUIPMENT_DIR "/obj/equipment/"
#define ACCESSORY_DIR "/obj/equipment/accessory/"
#define ARMOUR_DIR    "/obj/equipment/armour/"
#define WEAPON_DIR    "/obj/equipment/weapon/"
#define QUEST_DIR     "/feature/quest/"

// 指令路径
#define CMD_PATH_WIZ ({"/cmds/wiz/", "/mudcore/cmds/wizard/"})
#define CMD_PATH_STD ({"/cmds/std/", "/mudcore/cmds/player/"})
// 出生地
#define START_ROOM    "/world/start_room/0,0,0"
#define OCEAN         WORLD_9_DIR "43/sea"
// 系统公告
#define NOTICE        "/help/notice"
// 预加载列表
#define PRELOAD         "/system/etc/preload"
// 欢迎界面
#define MOTD            "/system/etc/motd"
// 聊天NPC
#define ROBOT_NPC       ({"/world/npc/ivy"})

#define F_CONDITION(x)  ("/feature/condition/" + x)
#define F_SKILL(x)      ("/feature/skill/" + x)
#define F_SPELL(x)      ("/feature/spell/" + x)
#define F_QUEST(x)      ("/feature/quest/" + x + ".c")

#define AUTO_LOOK
#define WIZARD  "ivy"

#define MAX_NAME_LEN 6

#define DAEMON_DIR  "/system/daemons/"
#define INHERIT_DIR "/inherit/"
#define STD_DIR     "/std/"

#include "_daemon.h"
#include "_inherit.h"
#include "_std.h"
#include "combat.h"
#include "condition.h"
#include "monster.h"
#include "object.h"

#include <mudcore.h>
