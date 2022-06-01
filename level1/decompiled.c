void run(void) {
	fwrite("Good... Wait what?\n", 19, 1, stdout);
	system("/bin/sh");
	return ;
}

int main(void) {
    char buffer[0x40]; // 0x50 - 0x40

    gets(buffer);
    return 0;
}