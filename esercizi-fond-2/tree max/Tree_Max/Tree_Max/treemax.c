#include "elemtype.h"
#include "tree.h"

const ElemType* BstTreeMax(const Node* n) {

	ElemType* max = TreeGetRootValue(n);

	if (TreeIsEmpty(n))
	{
		return NULL;
	}

	while (TreeRight(n))
	{
		max = TreeRight(n);
		n = TreeRight(n);
	}
	return max;

}

const ElemType* TreeMaxRec(const Node* n, ElemType *max) {

	if (TreeIsEmpty(n))
	{
		return NULL;
	}

	if (*max < n->value)
	{
		return *max = n->value;
	}
	if (TreeLeft(n))
	{
		TreeMaxRec(TreeLeft(n), max);
	}

	if (TreeRight(n))
	{
		TreeMaxRec(TreeRight(n), max);
	}
	return max;

}


const ElemType* TreeMax(const Node* n) {

	if (TreeIsEmpty(n))
	{
		return NULL;
	}
	ElemType* max = TreeGetRootValue(n);
	TreeMaxRec(n, max);
}