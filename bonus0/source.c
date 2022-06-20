const char separator[] = " - "

void    p (char *dest, const char *prompt) {
    char    buffer[0x1000]; // 4096

    puts( prompt );

    // Read stdin into buffer
    read( 0, buffer, 0x1000 ); // 4096
    
    // replace first occurence of '\n' by '\0'
    ret = strchr( buffer, '\n' );
    *ret = 0;
    
    // copy the first 20 characters into dest
    strncpy( dest, buffer, 0x14 ); // 20
}

void    pp (char *dest) {
    char    str1[20];
    char    str2[20];

    p( str1, separator );
    p( str2, separator );

    strcpy( dest, str1 );

    len = strlen( dest );
    dest[len] = " ";
    dest[len + 1] = 0;
    strcat( dest, str2 );
}

int main (void) {
    char	str[0x40 - 0x16]; // 0x2a = 42

	pp( str );
	puts( str );
	return (0);
}