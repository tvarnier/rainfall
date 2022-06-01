int main (int ac, char **av) {
    int     nb;
    char    *cmd[2];
    gid_t	gid;
	uid_t	uid;

    nb = atoi (av[1]);
    if (nb == 0x1a7) {
        cmd[0] = strdup("/bin/sh");
		cmd[1] = NULL;

		gid = getegid();
		uid = geteuid();

		setresgid(gid, gid, gid);
		setresuid(uid, uid, uid);

		execv("/bin/sh", cmd);
    }
    else
        fwrite("No !\n", 5, 1, stderr);
    return 0;
}
