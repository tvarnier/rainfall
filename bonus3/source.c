int	main(int ac, char **av)
{
	char	str1[0x42]; // 66 
	char	str2[0x41]; // 65
	FILE	*file;

	file = fopen("/home/user/end/.pass", "r");
	memset(str1, 0x21); // 33

	if (!file || ac != 2)
		return (-1);

	fread(str1, 1, 0x42, file); // 66
	str1[atoi(av[1])] = '\0';

	fread(str2, 1, 0x41, file); // 65
	fclose(file);

	if (strcmp(av[1], str1) == 0)
		execl("/bin/sh", "sh", 0);
	else
		puts(str1[0x42]); // 66

	return (0);
}