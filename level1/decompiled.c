/* jsdec pseudo code output */
/* /Users/tvarnier/42/import/level1 @ 0x8048480 */
#include <stdint.h>
 
int32_t main (void) {
    char * s;
    eax = &s;
    gets (eax);
    return eax;
}



int main (int argc, char **argv, char **envp);
; var char *s @ esp+0x10
0x08048480      push    ebp
0x08048481      mov     ebp, esp
0x08048483      and     esp, 0xfffffff0
0x08048486      sub     esp, 0x50
0x08048489      lea     eax, [s]
0x0804848d      mov     dword [esp], eax ; char *s
0x08048490      call    gets       ; sym.imp.gets ; char *gets(char *s)
0x08048495      leave