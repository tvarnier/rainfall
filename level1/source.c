void run(void) {
	fwrite( "Good... Wait what?\n", 0x13, 1, stdout ); //19
	system( "/bin/sh" );
	return ;
}

int main(void) {
    char buffer[0x40]; // 64

    gets( buffer );
    return (0);
}