int     lang = 0;

void    greetuser(char *user)
{
    char str[0x48]; // 72
    
    if (lang == 0)
        strcpy(str, "Hello ");
    else if (lang == 1)
        strcpy(str, "Hyv\xc3\xa4\xc3\xa4 p\xc3\xa4iv\xc3\xa4\xc3\xa4 "); // 18 characters
    else if (lang == 2)
        strcpy(str, "Goedemiddag! "); // 13 characters

    strcat(str, user);
    puts(str);
}

int main(int ac, char **av)
{
    char    str1[0x28]; // 40
    char    str2[0x20]; // 32
    char    *env;

    if (argc != 3)
        return 1;
    strncpy(str1, av[1], 0x28);
    strncpy(str2, av[2], 0x20);

    env = getenv("LANG");

    if (env != NULL) {
        if (memcmp(env, "fi", 2) == 0) {
            lang = 1;
        } else if (memcmp(env, "nl", 2) == 0) {
            lang = 2;
        }
    }
    greetuser(str1);
}