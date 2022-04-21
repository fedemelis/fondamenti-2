#include <stdlib.h>
#include <stdio.h>

void Hailstone(int n, int*ris, int index, int *quanti) {

	if (n == 1){
		*quanti += 1;
		printf("%i", n);
		return;
	}

	*quanti += 1;

	if ((n % 2) == 0)
	{
		printf("%i, ", n);
		n = n / 2;
		Hailstone(n, ris, index + 1, quanti);
	}
	else
	{
		printf("%i, ", n);
		n = (3 * n) + 1;
		Hailstone(n, ris, index + 1, quanti);
	}
}

int main(int argc, char* argv[]) {

	int * ris = malloc(sizeof(int));
	int quanti = 0;

	if (atoi(argv[1]) <= 0)
	{
		return 0;
	}

	if (argc != 2)
	{
		return -1;
	}

	Hailstone(atoi(argv[1]), ris, 0, &quanti);

	return quanti;

}