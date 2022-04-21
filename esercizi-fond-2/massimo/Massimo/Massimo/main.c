#include "max.h"

int main(void) {

    /*ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }*/

	Item* e1 = ListCreateEmpty();
	ElemType e = 3;

	e1 = ListInsertHead(&e, e1);
	e = 4;
	e1 = ListInsertHead(&e, e1);
	e = 2;
	e1 = ListInsertHead(&e, e1);
	e = 0;
	e1 = ListInsertHead(&e, e1);
	e = 45;
	e1 = ListInsertHead(&e, e1);
	e = 1;
	e1 = ListInsertHead(&e, e1);

    e = *(MaxElement(e1));

}