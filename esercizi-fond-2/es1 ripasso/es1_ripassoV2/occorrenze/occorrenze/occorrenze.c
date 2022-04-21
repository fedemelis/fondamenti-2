#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	int count = 0;

	if (argv[3] != NULL)
	{
		fprintf(stderr, "Il numero di parametri non è corretto.Sintassi del programma : occorenze <s> <c>");
		return 1;
	}
	else
	{
		for (size_t i = 0; i < strlen(argv[1]); i++)
		{
			if (argv[1][i] == argv[2][0])
			{
				count++;
			}
		}
		fprintf(stdout, "%i", count);
		return 0;
	}
}