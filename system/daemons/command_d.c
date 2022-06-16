inherit CORE_COMMAND_D;

void create()
{
    add_alias(([
        "hp" : "score -s",
        "news" : "help news",
    ]));
}
