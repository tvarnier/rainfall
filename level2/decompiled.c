int p (void) {
    char s[0x4c];
    void *eip;

    fflush (stdout);
    gets (s);
    if ((eip & 0xb0000000) == 0xb0000000)
        printf("(%p)\n", eip);
        exit (1);
    }
    puts (s);
    strdup (s);
    return eax;
}

int main (void) {
    p ();
    return 0;
}