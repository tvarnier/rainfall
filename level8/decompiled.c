char	*auth;
char	*service;

int		main(void)
{
	char	buf[0x80];
	
	while (1)
	{
		printf("%p, %p\n", auth, service);

		if (fgets(buf, 128, stdin) == 0)
			break ;
		
        if (strncmp(buf, "auth ", 5) == 0)
		{
			auth = malloc(4);
			if (strlen(buf + 5) <= 30)
				strcpy(auth, buf + 5);
		}
		if (strncmp(buf, "reset", 5) == 0)
			free(auth);
		if (strncmp(buf, "service", 6) == 0)
			service = strdup(buf + 7);
		if (strncmp(buf, "login", 5) == 0)
		{
			if (auth[0x20] != 0)
				system("/bin/sh");
			else
				fwrite("Password:\n", 10, 1, stdout);
		}
	}

    return 0;
}