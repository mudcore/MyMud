## MyMud 游戏开发基本准备

### 目录结构

计划的最终目录结构

目录|说明
-|-
system|系统文件目录
system/kernel|系统核心文件，包括master对象和simul_efun对象
system/daemons|系统守护进程
system/object|系统核心对象，包括登录对象、基本玩家对象和 VOID 环境
cmds|玩家指令目录
data|玩家数据存档目录和系统缓存目录
docs|游戏开发者文档，包括系统规范和模拟外部函数说明文档
feature|游戏特色文件，包括职业、技能等相关内容
help|游戏帮助文档，玩家游戏指南
include|游戏头文件
inherit|游戏特性继承文件
log|游戏日志文档
obj|游戏具体对象文件，继承标准对象的实物
std|游戏标准对象文件，不要直接放置到游戏中，需要被继承使用
wizard|游戏管理员工作目录
world|游戏世界地区文件
www|websocket服务，由 fluffos 驱动提供

### 基本目录结构

根据 config.ini 运行时配置文件的需求，准备如下目录和文件。

    .
    ├── config.ini              # 运行时配置文件
    ├── include                 # 头文件目录
    │   └── globals.h           # 全局包含头文件
    ├── log                     # 日志记录目录
    ├── mudcore                 # MudCore 框架
    ├── README.md               # 当前说明文档
    ├── system                  # 系统目录
    │   └── kernel              # 核心文件目录
    │       ├── master.c        # 主宰对象
    │       └── simul_efun.c    # 模拟外部函数对象
    └── www                     # WEBSOCKET HTTP 目录，FluffOS 驱动提供
