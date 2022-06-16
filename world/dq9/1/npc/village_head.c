inherit STD_NPC;

private create()
{
    ::create("common", 15);
    set_name("村长", ({"village head", "cun zhang"}));
    set("long", "这是沃尔罗村的村长，为了村子的发展和安全费心费力，深受村民的尊敬。");
    set("gender", "男性");
}
