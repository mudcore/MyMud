# MyMud 游戏框架

LPMUD游戏开发基本框架，可以在此基础上开发任何MUD，本框架需配合 FluffOS v2019使用。

### 目录结构

目录|说明
-|-
cmds|玩家指令目录
data|玩家数据存档目录和系统缓存目录
docs|游戏开发者文档，包括系统规范和模拟外部函数说明文档
feature|游戏特色文件，包括职业、技能等相关内容
help|游戏帮助文档，玩家游戏指南
include|游戏头文件
inherit|游戏特性继承文件
log|游戏日志目录
obj|游戏具体对象文件，继承标准对象的实物
std|游戏标准对象文件
system|系统文件目录
wizard|游戏管理员工作目录
world|游戏世界地区文件
www|websocket服务

#### system系统目录

目录|说明
-|-
system/kernel|系统核心文件，包括master对象和simul_efun对象
system/daemons|系统守护进程
system/object|系统核心对象，包括登录对象、基本玩家对象和 VOID 环境
system/etc|系统配置文件，包括登陆提示文件 motd 和预加载列表 preload

#### 核心对象

名称|文件路径|核心功能
-|-|-
MASTER_OB|/system/kernel/master|主控对象，负责接收玩家连接请求、安全验证、日志记录等核心功能
SIMUL_EFUN_OB|/system/kernel/simul_efun|模拟外部函数对象，负责实现模拟外部函数功能
LOGIN_OB|/system/object/login|玩家登陆对象
USER_OB|/system/object/user|玩家对象
VOID_OB|/system/object/void|临时环境，系统异常时会移动玩家到这个环境

#### 守护进程(Daemons)

守护进程是独立出来的系统服务，每个进程有自己的API可以调用，具体参考 `/docs/dameons/` 目录。

#### 系统头文件(Include Headers)

头文件在 `/include/` 目录中，主要是常量宏定义和函数声明，框架基本提供如下头文件：

文件|说明
-|-
globals.h|全局自动包含头文件，所有对象都会使用

#### 继承特征(Inherit Objects)

继承文件在 `/inherit/` 目录，实现了核心的功能片段，方便直接使用，具体参考 `/docs/inherit/` 目录。

#### 系统函数(Simul-Efuns)

除驱动自带的 efun 外，框架提供了部分模拟外部函数，具体参考 `/docs/simul_efun/` 目录。
