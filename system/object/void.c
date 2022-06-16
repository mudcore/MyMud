inherit STD_ROOM;

void create()
{
    ::create();
    set("exits", ([
        "down":START_ROOM,
    ]));
}
