#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
Item* ListLoad(const char* filename) {

	FILE *f = fopen(filename, "r");

	if (f == NULL)
	{
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();

	while (true)
	{
		char c = fgetc(f);
		int val = 0;
		if (!(c == EOF))
		{
			val = atoi(&c);
			c = fgetc(f);
			if (c != ' ' && c != EOF)
			{
				val = val * 10;
				val += atoi(&c);
				ris = ListInsertHead(&val, ris);
			}
			else
			{
				ris = ListInsertHead(&val, ris);
			}
		}
		else
		{
			break;
		}
	}

	fclose(f);
	return ris;
}	