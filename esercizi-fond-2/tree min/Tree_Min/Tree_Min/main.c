#include "treemin.h"

int main(void) {

    //tree 2
    ElemType v[] = { 21, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0 };
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

    TreeMin(t2);

}