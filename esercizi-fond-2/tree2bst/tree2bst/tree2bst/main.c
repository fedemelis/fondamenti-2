#include "tree2bst.h"

int main(void) {

    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    Node* t = TreeCreateRoot(&e[7],
        TreeCreateRoot(&e[5],
            TreeCreateRoot(&e[8], NULL, NULL),
            TreeCreateRoot(&e[8], NULL, NULL)),
        TreeCreateRoot(&e[1],
            TreeCreateRoot(&e[1], NULL, NULL),
            TreeCreateRoot(&e[2], NULL, NULL)));

    Tree2Bst(t);

    TreeDelete(t);

}