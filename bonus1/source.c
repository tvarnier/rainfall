int main (int ac, char **av) {
    size_t  n;
    char    str[40];

    n = atoi(av[1])
    if (n > 9)
        return (1);
    else {
        memcpy(str, av[2], n * 4);
        if (n == 0x574f4c46) // 1464814662
            execl("/bin/sh", "sh", 0);
    }
    return (0);
}