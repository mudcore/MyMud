inherit _CLEAN_UP;

int main(object me, string arg)
{
    if (arg)
    {
        printf("strlen(\"%s\") = %d\n", arg, strlen(arg));
    }

    return 1;
}
