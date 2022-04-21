#include "crea_da_interni.h"
#include "elemtype.h"
#include "list.h"

int main(void) {

	Item it[] = { (1, 2), (2, 4), (9, 2), (1, 5), (7, 2), (0, 2) };
	CreaDaInterni(it, 5);
}