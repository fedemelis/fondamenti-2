#include <stdbool.h>
#include <stdlib.h>

static bool IsPalindromoRec(const char* str, int index, int max) {

	if (index > max || max < index)
	{
		return true;
	}
	if (str[index] == str[max])
	{
		return IsPalindromoRec(str, index + 1, max - 1);
	}
	else
	{
		return false;
	}

}

bool IsPalindromo(const char* str) {

	int i = 0;
	int quanti = 0;

	if (str == NULL)
	{
		return false;
	}

	while (str[i] != 0)
	{
		++quanti;
		i += 1;
	}

	return IsPalindromoRec(str, 0, quanti-1);

}