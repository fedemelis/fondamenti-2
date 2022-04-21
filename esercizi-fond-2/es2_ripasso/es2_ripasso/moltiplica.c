#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	double res, uno, due = 0;

	if (argv[3] != NULL)
	{
		fprintf(stderr, "Il numero di parametri non è corretto.Sintassi del programma : mul <a> <b>");
		return 1;
	}
	else
	{
		uno = atoi(argv[1]);
		due = atoi(argv[2]);
		res = uno * due;
		fprintf(stdout, "%f", res);
		return 0;
	}
}