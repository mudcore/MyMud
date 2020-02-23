inherit CORE_COMMAND_D;

void create()
{
    add_alias(([
        "sc" : "score",
        "hp" : "score -s",
    ]));
}
