unsigned long long Fattoriale(int n) {

	if (n <= 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	return n * (Fattoriale(n - 1));

}


int main(void) {

	int a = Fattoriale(4);

}