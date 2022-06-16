const char separator[] = " - "

void p (char *dest, const char *prompt) {
    char    buffer[0x1000]; // 4096

    puts (prompt);
    read(0, buffer, 0x1000); // 4096
    ret = strchr(buffer, '\n');
    *ret = 0; // replace first occurence of '\n' by '\0'
    strncpy(dest, buffer, 0x14); // 20
}

void pp (char *dest) {
    char    str1[20];
    char    str2[20];

    p(str1, separator);
    p(str2, separator);

    strcpy(dest, str1);

    len = strlen(dest);
    dest[len] = " ";
    dest[len + 1] = 0;
    strcat(dest, str2);
}

int main (void) {
    char	str[42];

	pp(str);
	puts(str);
	return (0);
}