inherit STD_NPC;

void create()
{
    ::create("warrior", 20);
    set_name("守卫", ({"guard"}));
    set("long", "这是一个守卫，他穿着厚厚的铠甲，握着长枪，防止魔物的袭击。");
}
