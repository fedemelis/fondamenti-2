#include "check_sum_n.h"

int main(void) {

    //tree 1
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    Node* t1 = TreeCreateRoot(&e[4], TreeCreateRoot(&e[2], TreeCreateRoot(&e[1], NULL, NULL), NULL), TreeCreateRoot(&e[5], NULL, NULL));

    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Node* t2 = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1],
            TreeCreateRoot(&v[3],
                TreeCreateRoot(&v[5], NULL, NULL),
                TreeCreateRoot(&v[6],
                    TreeCreateRoot(&v[9], NULL, NULL),
                    NULL)),
            TreeCreateRoot(&v[4],
                TreeCreateRoot(&v[7], NULL, NULL),
                TreeCreateRoot(&v[8],
                    NULL,
                    NULL))),
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[4],
            TreeCreateRoot(&v[8], NULL, NULL),
            TreeCreateRoot(&v[7],
                NULL,
                NULL)),
            TreeCreateRoot(&v[3],
                TreeCreateRoot(&v[6], NULL, TreeCreateRoot(&v[9], NULL, NULL)),
                TreeCreateRoot(&v[5],
                    NULL,
                    NULL))));


    bool b = CheckSumN(t2, 5);

    TreeDelete(t1);
    TreeDelete(t2);
}