## MyMud 游戏

> 当前版本:v2.3

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

### 目录结构

当前版本主要目录和文件:

    .
    ├── config.cfg              # 运行时配置文件
    ├── cmds                    # 指令目录
    ├── data                    # 存档目录(框架会自动生成)
    ├── help                    # 帮助目录
    ├── include                 # 头文件目录
    │   └── globals.h           # 全局包含头文件
    ├── inherit                 # 功能模块接口
    ├── log                     # 日志记录目录(框架会自动生成)
    ├── mudcore                 # MudCore 框架
    ├── obj                     # 通用游戏对象
    ├── std                     # 标准对象模板
    ├── README.md               # 当前说明文档
    ├── system                  # 系统目录
    │   └── kernel              # 核心文件目录
    │       ├── master.c        # 主宰对象
    │       └── simul_efun.c    # 模拟外部函数对象
    ├── world                   # 游戏世界目录
    ├── wizard                  # 开发者工作目录
    └── www                     # WEBSOCKET HTTP 目录，FluffOS 驱动提供

 * mudcore 框架地址：https://github.com/oiuv/mudcore
 * www 项目地址：https://github.com/MudRen/www
