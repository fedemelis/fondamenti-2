#include "domino.h"

int main(void) {

	Tessera t[] = { {.val1 = 5, .val2 = 3 }, {.val1 = 5, .val2 = 6 }, {.val1 = 6, .val2 = 2 }, {.val1 = 5, .val2 = 6 }, {.val1 = 3, .val2 = 2 }, {.val1 = 3, .val2 = 1 } };
	size_t* retsize = 0;
	Domino(t, 6, &retsize);
}