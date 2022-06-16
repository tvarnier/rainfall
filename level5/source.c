void    o (void) {
    system( "/bin/sh" );
    return exit( 1 );
}

int     n (void) {
    char format[0x218]; // 536

    fgets( format, 0x200, stdin ); //512
    printf( format );
    return exit( 1 );
}

int     main (void) {
    n();
}