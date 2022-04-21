#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ToUpper(char* str) {

	if (str == NULL)
	{
		return;
	}
	
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (islower(*(str+i)))
		{
			*(str+i) -= 32;
		}
	}

}

/*int main(void) {

	char c[] = "siuuum";
	ToUpper(c);

}*/