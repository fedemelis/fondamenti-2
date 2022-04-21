#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	char c = argv[2];
	int count = 0;

	if (argc >= 4 || argc <= 2)
	{
		fprintf(stderr, "messaggio di errore");
		return 1;
	}

	for (size_t i = 0; i < strlen(argv[1]); i++)
	{
		if (argv[1][i] == argv[2][0])
		{
			fprintf(stdout, "%s", &argv[2][0]);
			count++;
		}
	}

	return 0;
}