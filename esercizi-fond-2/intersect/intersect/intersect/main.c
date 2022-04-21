#include "intersect.h"

int main(void) {

	Item* l1 = ListCreateEmpty();
	Item* l2 = ListCreateEmpty();
	ElemType e = 1;

	l1 = ListInsertHead(&e, l1);
	e = 3;
	l1 = ListInsertHead(&e, l1);
	e = 1;
	l1 = ListInsertHead(&e, l1);

	e = 1;
	l2 = ListInsertHead(&e, l2);
	e = 6;
	l2 = ListInsertHead(&e, l2);
	e = 2;
	l2 = ListInsertHead(&e, l2);

	Intersect(l1, l2);

	ListDelete(l1);
	ListDelete(l2);
}