// The global include file is included automatically.
#ifndef GLOBALS_H
#define GLOBALS_H

// 游戏管理员帐号
#define WIZARD "test"

// 功能模块
#include "inherit.h"
// 守护进程
#include "daemons.h"
// 标准继承对象
#include "stdob.h"

// 指令路径
#define CMD_PATH_WIZ ({"/cmds/wiz/", "/mudcore/cmds/wizard/"})
#define CMD_PATH_STD ({"/cmds/std/", "/mudcore/cmds/player/"})

// 其他
#define MOTD    "/system/etc/motd"
#define PRELOAD "/system/etc/preload"

// mudcore框架头文件（请放在最底部）
#include <mudcore.h>

#endif
