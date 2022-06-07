class N {
	char str[100];
	int nbr;

	N(int nbr) {
		this->nbr = nbr;
	}

	int operator+(N &other) {
		return this->nbr + other.nbr;
	}
    int operator-(N &other) {
		return this->nbr - other.nbr;
	}

	void setAnnotation(char *str) {
		size_t len;

		len = strlen(str);
		memcpy(this->str, str, len);
	}
};

int main(int ac,char **av) {
	N *obj1;
	N *obj2;

	if (ac < 2) {
		exit(1);
	}

	obj1 = new N(5);
	obj2 = new N(6);
	obj1->setAnnotation(av[1]);
	return *obj2 + *obj1;;
}