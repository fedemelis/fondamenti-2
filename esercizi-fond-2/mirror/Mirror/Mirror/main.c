#include "mirror.h"

int main(void) {

    //tree 1
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    Node* t1 = TreeCreateRoot(&e[0],
        TreeCreateRoot(&e[1],
            TreeCreateRoot(&e[2], NULL, NULL), NULL),
        //TreeCreateRoot(&e[3], NULL, NULL)),
        TreeCreateRoot(&e[1], NULL, NULL));
            /*TreeCreateRoot(&e[3], NULL, NULL), 
            TreeCreateRoot(&e[2], NULL, NULL)));*/

            //tree 2
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Node* t2 = TreeCreateRoot(&v[0],
        TreeCreateRoot(&v[1],
            TreeCreateRoot(&v[2],
                TreeCreateRoot(&v[3], NULL, NULL),
                TreeCreateRoot(&v[3],
                    TreeCreateRoot(&v[4], NULL, NULL),
                    NULL)),
            TreeCreateRoot(&v[2],
                TreeCreateRoot(&v[3], NULL, NULL),
                TreeCreateRoot(&v[3],
                    NULL,
                    NULL))),
        TreeCreateRoot(&v[1], TreeCreateRoot(&v[5],
            TreeCreateRoot(&v[2], NULL, NULL),
            TreeCreateRoot(&v[2],
                NULL,
                NULL)),
            TreeCreateRoot(&v[2],
                TreeCreateRoot(&v[3], NULL, TreeCreateRoot(&v[6], NULL, NULL)),
                TreeCreateRoot(&v[3],
                    NULL,
                    NULL))));

    TreeIsMirror(t1);
    TreeDelete(t2);

    //TreeIsMirror(t1);

    TreeDelete(t1);

}