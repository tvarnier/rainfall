void o (void) {
    system ("/bin/sh");
    return exit (1);
}

int32_t n (void) {
    char format[0x218];

    fgets(format, 0x200, stdin);
    printf (format);
    return exit (1);
}

int32_t main (void) {
    n ();
}