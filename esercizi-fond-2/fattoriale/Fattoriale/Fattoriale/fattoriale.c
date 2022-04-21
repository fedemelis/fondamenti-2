unsigned long long FattorialeRec(int n, int * ris) {

	if (n == 1)
	{
		return;
	}

	*ris = n * (FattorialeRec(n - 1, ris));
	return ris;
}

unsigned long long Fattoriale(int n) {

	if (n < 0)
	{
		return;
	}

	int ris = 0;

	return FattorialeRec(n, &ris);
}

int main(int argc, char *argv[]) {

	int ris = Fattoriale(atoll(argv[1]));

}