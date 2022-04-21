#include "common_tail.h"

int main(void) {

    //lista 1
    ElemType e1[] = { 2, 5, 4, 1 };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    /*for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }*/

    list_a = ListInsertBack(list_a, e1 + 1);
    list_a = ListInsertBack(list_a, e1 + 2);
    list_a = ListInsertBack(list_a, e1 + 3);

    //lista 2
    ElemType e2[] = { 2 };
    size_t e2_size = sizeof(e2) / sizeof(ElemType);

    Item* list_b = ListCreateEmpty();
    /*for (size_t i = 0; i < e2_size; ++i) {
        list_b = ListInsertBack(list_b, e2 + i);
    }*/

    list_b = ListInsertBack(list_b, e1);
    list_b = ListInsertBack(list_b, e1 + 1);
    list_b = ListInsertBack(list_b, e1 + 2);
    list_b = ListInsertBack(list_b, e1 + 3);
   
    list_a = list_b;

    CommonTail(list_a, list_b);

}