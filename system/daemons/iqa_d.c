// iqa - 智能应答机器人
#include <ansi.h>

#define STREAM 1
#define EESUCCESS 1

nosave mapping status = ([]);
nosave object receiver;

private void write_data(int fd)
{
    socket_write(fd, "POST " + status[fd]["path"] + " HTTP/1.1\nHost: " + status[fd]["host"] + "\nContent-Type: application/json;charset=UTF-8\nX-Bce-Signature: AppCode/"+ status[fd]["code"] + "\r\n\r\n");
}

private void receive_data(int fd, mixed result)
{
    string res;
    // debug_message(result);
    res = trim(result[strsrch(result, "content") + 10 .. strsrch(result, "relquestion") - 4]);
    // res = result[strsrch(result, "{")..strsrch(result, "}", -1)];
    // debug_message(result);
    // 清理转义字符
    // res = replace_string(res, "\\r\\n", "\n\t");
    // res = replace_string(res, "\\n\\t", "\n\t");
    res = replace_string(res, "\\r", "\r");
    res = replace_string(res, "\\n", "\n");
    res = replace_string(res, "\\t", "\t");
    res = replace_string(res, "\\/s", "");
    res = replace_string(res, "\\", "");
    // 替换默认回复
    res = replace_string(res, "defaultReply", "...");
    // debug_message(sprintf("%d || %O", strlen(result), result));
    // tell_object(receiver, res);
    if (sizeof(res) < 3)
    {
        return;
    }

    CHANNEL_D->do_channel(receiver, "chat", res);
}

private void receive_callback(int fd, mixed result, string addr)
{
    // 此方法无效
}

private void socket_shutdown(int fd)
{
    socket_close(fd);
}

int main(object me, string arg)
{
    int fd;
    int ret;
    string host = "jisuapiareacode.api.bdymkt.com";
    string addr = "157.255.71.211 80";
    string path = "/iqa/query?question=" + arg;
    string code = config("IQA_CODE");

    receiver = me;

    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["host"] = host;
    status[fd]["path"] = path;
    status[fd]["code"] = code;

    ret = socket_connect(fd, addr, "receive_data", "write_data");
    if (ret != EESUCCESS)
    {
        tell_object(receiver, "服务器连接失败。\n");
        socket_close(fd);
    }

    return 1;
}
