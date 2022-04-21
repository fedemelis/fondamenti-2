#include "treemax.h"

Node* BstInsertRec(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
        // Va a sinistra
        n->left = BstInsertRec(e, TreeLeft(n));
    }
    else {
        // Va a destra
        n->right = BstInsertRec(e, TreeRight(n));
    }
    return n;
}

Node* BstFromVector(ElemType* v, size_t v_size) {
    Node* tree = TreeCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        tree = BstInsertRec(v + i, tree);
    }
    return tree;
}

int main(void) {

    ElemType key = 12;
    ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
    size_t e_size = sizeof(e) / sizeof(ElemType);
    Node* t = BstFromVector(e, e_size);
    TreeMax(t);
    TreeDelete(t);

}