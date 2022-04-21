#include "diameter.h"

int main(void) {

    //tree 2
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Node* t2 = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[2], NULL, NULL), NULL), TreeCreateRoot(&v[1], NULL, NULL));

    Diameter(t2);

    TreeDelete(t2);

}