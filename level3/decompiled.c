int m;

void v(void) {
	char format[0x200];

	fgets(format, 0x200, stdin);
	printf(format);
	if (m == 0x40) {
		fwrite("Wait what?!\n", 1, 12, stdout);
		system("/bin/sh");
	}
	return ;
}

int main(void) {
	v();
	return 0;
}
