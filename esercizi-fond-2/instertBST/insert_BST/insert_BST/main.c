#include "elemtype.h"
#include "tree.h"
#include "insert.h"


int main(void) {

    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 15,
        TreeCreateRoot(e + 10,
            TreeCreateRoot(e + 3, NULL, NULL),
            TreeCreateRoot(e + 12, NULL, NULL)),
        TreeCreateRoot(e + 21, NULL, NULL));

    t = BstInsertRec(e + 22, t);
    TreeDelete(t);
    return 0;

}