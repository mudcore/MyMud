# lpc-test
> LPMUD编程语言LPC底层代码测试

<pre>
┌-----------------------------ooO-----Ooo-----------------------------------┐
|  ★
|  ★ LPMUD启动顺序：
|  ★ simul_efun
|  ★ master
|  ★    get_root_uid - author_file - get_bb_uid - domain_file
|  ★    epilog - preload
|  ★
|  ★ 玩家连线调用：
|  ★    master中的object connect(int port)方法
|  ★    connect方法传回对象中的object logon()方法
|  ★
|  ★ 所有文件都会#include <globals.h>
|  ★ 所有文件载入时都会调用master中的以下方法（apply）：
|  ★    domain_file、author_file、creator_file
|  ★ 所有文件都会执行文件中的void create()方法（apply）
|  ★
|  ★ move_object() 呼叫对象中的 init() 以初始化動詞(verb)或動作(action)
|  ★ 如果一個对象曾呼叫 set_heart_beat()，此对象會定期呼叫void heart_beat()
|  ★
|  ★ 更多细节请查阅 apply 和 efun 文档
└---------------------------------------------------------------------------┘
</pre>
