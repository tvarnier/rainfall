int m;

void v(void) {
	char format[0x200]; // 512

	fgets( format, 0x200, stdin ); // 512
	printf( format );
	if (m == 0x40) { // 64
		fwrite( "Wait what?!\n", 1, 0xc, stdout ); // 12
		system( "/bin/sh" );
	}
	return ;
}

int main(void) {
	v();
	return (0);
}
