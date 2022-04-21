#include <stdlib.h>
#include <stdio.h>

void RadicenumericaRec(int val, int **ris, int * quanti) {

	if (val == 0)
	{
		return;
	}

	*ris = realloc(*ris, sizeof(int) * (*quanti + 1));
	ris[0][*quanti] = val % 10;
	*quanti += 1;
	val = val / 10;

	RadicenumericaRec(val, ris, quanti);
	
}

int main(int argc, char* argv[]) {

	if (argc != 2 || atoi(argv[1]) < 0)
	{
		return 1;
	}

	if (atoi(argv[1]) == 0)
	{
		printf("0");
		return 0;
	}

	int* ris = malloc(sizeof(int));
	int quanti = 0;

	int val = 0;
	val = atoi(argv[1]);

	while (quanti != 1)
	{
		quanti = 0;
		RadicenumericaRec(val, &ris, &quanti);
		val = 0;
		for (size_t i = 0; i < quanti; i++)
		{
			val = ris[i] + val;
		}
	}

	printf("%d", val);

	return 0;
}