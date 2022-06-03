uint32_t m (void) {
    int32_t var_4h;
    time_t var_8h;
    eax = time (0);
    edx = "%s - %d\n";
    var_8h = eax;
    var_4h = c;
    printf (edx);
    return eax;
}


int32_t main (char ** envp) {
    const char * size;
    FILE * stream;
    void ** var_18h;
    void ** var_1ch;
    eax = malloc (8);
    *(eax) = 1;
    eax = malloc (8, eax);
    edx = eax;
    eax = var_1ch;
    *((eax + 4)) = edx;
    eax = malloc (8);
    *(eax) = 2;
    eax = malloc (8, eax);
    edx = eax;
    eax = var_18h;
    *((eax + 4)) = edx;
    eax = envp;
    eax += 4;
    eax = *(eax);
    edx = *(eax);
    eax = var_1ch;
    eax = *((eax + 4));
    strcpy (eax, edx);
    eax = envp;
    eax += 8;
    eax = *(eax);
    edx = *(eax);
    eax = var_18h;
    eax = *((eax + 4));
    strcpy (eax, edx);
    edx = 0x80486e9;
    eax = "/home/user/level8/.pass";
    eax = fopen (eax, edx);
    fgets (c, eax, 0x44);
    puts (0x8048703);
    eax = 0;
    return eax;
}