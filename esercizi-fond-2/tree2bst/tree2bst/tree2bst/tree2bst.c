#include "elemtype.h"
#include "tree.h"

void TreeInsertRec(Node** tree, ElemType* e) {

	if (TreeIsEmpty(*tree))
	{
		Node* new = TreeCreateRoot(e, NULL, NULL);
		*tree = new;
		return;
	}

	if (ElemCompare(e, TreeGetRootValue(*tree)) <= 0)
	{
		TreeInsertRec(&(*tree)->left, e);
	}
	else
	{
		TreeInsertRec(&(*tree)->right, e);
	}

}

Node* Tree2BstRec(const Node* t, Node ** ris) {

	if (TreeIsEmpty(t))
	{
		return NULL;
	}

	Tree2BstRec(TreeLeft(t), ris);
	TreeInsertRec(ris, TreeGetRootValue(t));
	Tree2BstRec(TreeRight(t), ris);

}

Node* Tree2Bst(const Node* t) {

	Node* ris = NULL;

	if (TreeIsEmpty(t))
	{
		return ris;
	}

	Tree2BstRec(t, &ris);

	return ris;
}
