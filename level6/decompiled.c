void m (void) {
    puts ("Nope");
}

void n (void) {
    system ("/bin/cat /home/user/level7/.pass");
}

int32_t main (char ** envp) {
    const char * src;
    void * var_18h;
    char * dest;
    eax = malloc (0x40);
    eax = malloc (4, eax);
    var_18h = eax;
    edx = m;
    eax = var_18h;
    *(eax) = edx;
    eax = envp;
    eax += 4;
    eax = *(eax);
    edx = *(eax);
    eax = dest;
    strcpy (eax, edx);
    eax = var_18h;
    eax = *(eax);
    void (*eax)() ();
    return eax;
}