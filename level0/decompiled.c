/* jsdec pseudo code output */
/* /Users/tvarnier/42/import/level0 @ 0x8048ec0 */
#include <stdint.h>
 
int32_t main (char ** envp) {
    int32_t var_4h;
    int32_t var_8h;
    int32_t var_ch;
    int32_t var_10h;
    int32_t var_14h;
    uid_t var_18h;
    int32_t var_1ch;
    eax = envp;
    eax += 4;
    eax = *(eax);
    eax = atoi (eax);
    if (eax == 0x1a7) {                                 // eax == 423 ?
        eax = _strdup ("/bin/sh");
        eax = getegid (eax, 0);
        eax = geteuid (eax);
        eax = var_1ch;
        eax = var_1ch;
        eax = var_1ch;
        _setresgid (eax, eax, var_1ch, var_1ch);
        eax = var_18h;
        eax = var_18h;
        eax = var_18h;
        setresuid (eax, var_18h, var_18h);
        eax = &var_10h;
        execv ("/bin/sh", eax);
    } else {
        eax = *(stderr);
        edx = *(stderr);
        eax = "No !\n";
        _IO_fwrite (eax, edx, 5, 1);
    }
    eax = 0;
    return eax;
}
