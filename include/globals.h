// The global include file is included automatically.
#ifndef GLOBALS_H
#define GLOBALS_H

// 游戏管理员帐号
#define WIZARD "test"

// 指令路径
#define CMD_PATH_WIZ ({"/cmds/wiz/", "/mudcore/cmds/wizard/"})
#define CMD_PATH_STD ({"/cmds/std/", "/mudcore/cmds/player/"})

// mudcore框架头文件（请放在最底部）
#include <mudcore.h>

#endif
