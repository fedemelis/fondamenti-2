#include <stdlib.h>

static char* ReverseStringRec(const char* str, int *indexR, int* size, int index, char *ris) {

	if (index == *size)
	{
		return;
	}

	ReverseStringRec(str, indexR, size, index + 1, ris);
	ris[*indexR] = str[index];
	*indexR += 1;
	ris[*indexR] = 0;
	return ris;
}

char* ReverseString(const char* str) {

	if (str == NULL)
	{
		return NULL;
	}


	int quanti = 0;
	int size = 0;
	
	while (str[quanti] != 0)
	{
		++quanti;
	}


	char* ris = calloc((quanti+1), sizeof(char));

	if (quanti == 0)
	{
		return ris;
	}

	ReverseStringRec(str, &size, &quanti, 0, ris);

	return ris;
}