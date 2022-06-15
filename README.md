## MyMud 游戏

> 当前版本: v3.*

### 目录结构

本游戏为使用mudcore开发新MUD的示例项目，计划的最终目录结构如下：

目录|说明
-|-
cmds|玩家action指令目录
data|玩家数据存档目录和系统缓存目录
docs|游戏开发者文档，包括系统规范和模拟外部函数说明文档
feature|游戏特色文件，包括职业、技能等相关内容
help|游戏帮助文档，玩家游戏指南
include|游戏头文件
inherit|游戏特性继承文件
log|游戏日志文档
mudcore|泥芯游戏框架
obj|游戏具体对象文件，继承标准对象的实物
std|游戏标准对象文件，不要直接放置到游戏中，需要被继承使用
system|系统文件目录
verbs|玩家游戏指令目录
wizard|游戏管理员工作目录
world|游戏世界地区文件
www|websocket服务，由 fluffos 驱动提供

其中mudcore和www为子模块：

 * mudcore 框架地址：https://github.com/mudcore/mudcore
 * www http项目地址：https://github.com/MudRen/www

system系统文件目录包括以下核心目录

目录|说明
-|-
system/daemons|系统守护进程
system/etc|系统配置文件
system/kernel|系统核心文件，包括master对象和simul_efun对象
system/object|系统核心对象，包括登录对象、基本玩家对象和 VOID 环境

### 使用说明

本游戏是基于mudcore框架的项目，安装方式：

    git clone --recurse-submodules https://github.com/mudcore/MyMud.git

或

    git clone https://github.com/mudcore/MyMud.git
    git submodule update --init --recursive

如需更新框架，请在项目根目录执行以下指令：

    git submodule update --remote

服务端使用FluffOS v2019驱动：

    driver config.cfg
