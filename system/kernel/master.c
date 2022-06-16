inherit CORE_MASTER_OB;

void create()
{
}

string *epilog(int load_empty)
{
    string *items = ({PRELOAD_D});

    return items;
}

// preload an object
void preload(string file)
{
    string err;

    if (file_size(file + ".c") == -1)
        return;

    err = catch (load_object(file));
    if (err != 0)
    {
        write("[MASTER_OB]->preload():Error " + err + " when loading " + file + "\n");
    }
}
