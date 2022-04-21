#include "elemtype.h"
#include "tree.h"

const ElemType* BstTreeMin(const Node* n) {

	if (!TreeLeft(n))
	{
		return &n->value;
	}

	if (TreeLeft(n))
	{
		BstTreeMin(n->left);
	}

}

const ElemType* TreeMinRec(const Node* n, ElemType* min) {

	if (TreeIsEmpty(n))
	{
		return;
	}

	if (n->value < *min)
	{
		min = &n->value;
	}

	if (TreeLeft(n))
	{
		TreeMinRec(TreeLeft(n), min);
	}
	if (TreeRight(n))
	{
		TreeMinRec(TreeRight(n), min);
	}

	return min;
}

const ElemType* TreeMin(const Node* n) {

	if (TreeIsEmpty(n))
	{
		return NULL;
	}

	if (TreeIsLeaf(n))
	{
		return &n->value;
	}

	ElemType *min = TreeGetRootValue(n);

	TreeMinRec(n, min);
}