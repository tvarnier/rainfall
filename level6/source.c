void    n (void) {
    system( "/bin/cat /home/user/level7/.pass" );
}

void    m (void) {
    puts( "Nope" );
}

int     main (int ac, char **av) {
    char *str;
    void (*fct)(void);

    str = (char *)malloc( 0x40 ); // 64
    fct = (void **)malloc( 0x4 );

    fct = &m;
    strcpy( str, av[1] );

    fct();
    return 0;
}