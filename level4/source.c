int m;

int p (char *format) {
    printf( format );
    return ;
}

int n (void) {
    char format[0x200]; // 512

	fgets( format, 0x200, stdin ); // 512
    p( format );
    if (m == 0x1025544) // 16930116
        system( "/bin/cat /home/user/level5/.pass" );
    return  ;
}

int main (void) {
    n();
}