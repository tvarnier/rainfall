/* jsdec pseudo code output */
/* /Users/tvarnier/42/import/level4 @ 0x80484a7 */
#include <stdint.h>
 
int32_t main (void) {
    n ();
}

/* jsdec pseudo code output */
/* /Users/tvarnier/42/import/level4 @ 0x8048457 */
#include <stdint.h>
 
int32_t n (void) {
    char * s;
    int32_t size;
    FILE * stream;
    eax = *(stdin);
    eax = &s;
    fgets (eax, *(stdin), 0x200);
    eax = &s;
    p (eax);
    eax = m;
    if (eax == 0x1025544) {
        system ("/bin/cat /home/user/level5/.pass");
    }
    return eax;
}

/* jsdec pseudo code output */
/* /Users/tvarnier/42/import/level4 @ 0x8048444 */
#include <stdint.h>
 
int32_t p (const char * format) {
    eax = format;
    printf (eax);
    return eax;
}

Dump of assembler code for function main:
   0x080484a7 <+0>:     push   %ebp
   0x080484a8 <+1>:     mov    %esp,%ebp
   0x080484aa <+3>:     and    $0xfffffff0,%esp
   0x080484ad <+6>:     call   0x8048457 <n>
   0x080484b2 <+11>:    leave  
   0x080484b3 <+12>:    ret

Dump of assembler code for function n:
   0x08048457 <+0>:     push   %ebp
   0x08048458 <+1>:     mov    %esp,%ebp
   0x0804845a <+3>:     sub    $0x218,%esp
   0x08048460 <+9>:     mov    0x8049804,%eax
   0x08048465 <+14>:    mov    %eax,0x8(%esp)
   0x08048469 <+18>:    movl   $0x200,0x4(%esp)
   0x08048471 <+26>:    lea    -0x208(%ebp),%eax
   0x08048477 <+32>:    mov    %eax,(%esp)
   0x0804847a <+35>:    call   0x8048350 <fgets@plt>
   0x0804847f <+40>:    lea    -0x208(%ebp),%eax
   0x08048485 <+46>:    mov    %eax,(%esp)
   0x08048488 <+49>:    call   0x8048444 <p>
   0x0804848d <+54>:    mov    0x8049810,%eax
   0x08048492 <+59>:    cmp    $0x1025544,%eax
   0x08048497 <+64>:    jne    0x80484a5 <n+78>
   0x08048499 <+66>:    movl   $0x8048590,(%esp)
   0x080484a0 <+73>:    call   0x8048360 <system@plt>
   0x080484a5 <+78>:    leave  
   0x080484a6 <+79>:    ret

Dump of assembler code for function p:
   0x08048444 <+0>:     push   %ebp
   0x08048445 <+1>:     mov    %esp,%ebp
   0x08048447 <+3>:     sub    $0x18,%esp
   0x0804844a <+6>:     mov    0x8(%ebp),%eax
   0x0804844d <+9>:     mov    %eax,(%esp)
   0x08048450 <+12>:    call   0x8048340 <printf@plt>
   0x08048455 <+17>:    leave  
   0x08048456 <+18>:    ret 