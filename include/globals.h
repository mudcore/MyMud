// The global include file is included automatically.
#ifndef GLOBALS_H
#define GLOBALS_H

// 游戏管理员帐号
#define WIZARD "test"

// 系统目录
#define WORLD_DIR "/world/"

// 核心对象
#include "object.h"
// 功能模块
#include "inherits.h"
// 守护进程
#include "daemons.h"
// 标准继承对象
#include "stdob.h"

// 指令路径
#define CMD_PATH_WIZ ({"/cmds/wiz/", "/mudcore/cmds/wizard/"})
#define CMD_PATH_STD ({"/cmds/std/", "/mudcore/cmds/player/"})

// 其他
#define MOTD "/system/etc/motd"
#define PRELOAD "/system/etc/preload"

#define START_ROOM WORLD_DIR "start_room"

// mudcore框架头文件（请放在最底部）
#include <mudcore.h>

#endif
