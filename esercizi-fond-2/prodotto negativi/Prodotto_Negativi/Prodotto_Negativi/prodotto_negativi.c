int ProdottoNegativiRecPositive(int a, int b, int quanteVolte, int * ris) {

	if (quanteVolte == b)
	{
		return;
	}

	if (true)
	{

	}

}

int ProdottoNegativiRecNegative(int a, int b, int quanteVolte, int* ris) {

	if (quanteVolte == b)
	{
		return;
	}

	if (true)
	{

	}

}

int ProdottoNegativi(int a, int b) {

	if (a == 0 || b == 0)
	{
		return 0;
	}

	if (a == 1)
	{
		return b;
	}

	if (b == 1)
	{
		return a;
	}

	int ris = 0;

	if (a > 0 || b > 0)
	{
		ProdottoNegativiRecPositive(a, b, b, &ris);
	}
	else if(a > 0 || b < 0)
	{
		ProdottoNegativiRecNegative(a, b, b, &ris);
	}
	else if (a < 0 || b > 0)
	{
		ProdottoNegativiRecNegative(a, b, b, &ris);
	}
	else if ()
	{

	}
}