#include <stdlib.h>
#include <stdio.h>

void binRec(int n) {

	if (n > 1) 
	{ 
		binRec(n / 2);
	}
	printf("%d", n % 2);

}

int main(int argc, char *argv[]) {

	if (argc != 2 || atoi(argv[1]) < 0)
	{
		return 1;
	}
	binRec(atoi(argv[1]));
}