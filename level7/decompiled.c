char    c[0x44];

void m (void) {
    printf("%s - %d\n", c, time(0));
}


int main (int ac, char **av) {
    int     *str1;
    int     *str2;

    str1 = malloc(8);
	str1[0] = 1;
	str1[1] = (int)malloc(8);

    str2 = malloc(8);
	str2[0] = 2;
	str2[1] = (int)malloc(8);

    strcpy((char *)str1[1], av[1]);
	strcpy((char *)str2[1], av[2]);

    fgets(c, 0x44, fopen("/home/user/level8/.pass","r"));
    puts("~~");

    return 0;
}