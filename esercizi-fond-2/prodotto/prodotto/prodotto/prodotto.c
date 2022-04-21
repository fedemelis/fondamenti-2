//#include "prodotto.h"

static int ProdottoRec(int a, int b) {

	if (b == 0)
	{
		return 0;
	}

	return a + (ProdottoRec(a, b - 1));

}

int Prodotto(int a, int b) {

	if (a < 0 || b < 0)
	{
		return -1;
	}

	if (b == 0 || a == 0)
	{
		return 0;
	}

	return a + (ProdottoRec(a, b - 1));

}