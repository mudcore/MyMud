// The global include file is included automatically.
#ifndef GLOBALS_H
#define GLOBALS_H

// 系统目录
#define WORLD_DIR   "/world/"

// 功能模块
#include "inherit.h"
// 守护进程
#include "daemons.h"
// 标准继承对象
#include "stdob.h"

// 其他
#define MOTD    "/system/etc/motd"
#define PRELOAD "/system/etc/preload"

#define START_ROOM  WORLD_DIR "start_room"

#define AUTO_LOOK
#define WIZARD "test"

// mudcore框架头文件（请放在最底部）
#include <mudcore.h>

#endif
