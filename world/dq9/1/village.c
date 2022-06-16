/**
 * @brief 区域模式示例，进入区域后可用sa指令建设地区
 *
 */
inherit STD_AREA;

void create()
{
    set("name", "沃尔罗村");
    set("x_axis_size", 49);    // 橫向大小
    set("y_axis_size", 29);     // 縱向大小
    setup();
}
