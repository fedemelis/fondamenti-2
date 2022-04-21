#include "elemtype.h"	
#include "tree.h"


const ElemType* BstTreeMax(const Node* n) {

	if (TreeIsEmpty(n))
	{
		return NULL;
	}
		
	Node* ris = TreeCreateEmpty();

	while (TreeRight(n))
	{
		n = TreeRight(n);
	}

	return &n->value;

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

	ElemType *ris = TreeGetRootValue(n);

	TreeMaxRec(n, ris);
}

