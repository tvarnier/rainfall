# Level0

## Analysis

**In `main` :**

This program takes the first argument and check if its equal to `0x1a7`
If it does, it open a shell with `level1` access

___

## Exploit

```bash
level0@RainFall:~$ ./level0 423
$ whoami
level1
$ cat /home/user/level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```

___

*Password: level0*