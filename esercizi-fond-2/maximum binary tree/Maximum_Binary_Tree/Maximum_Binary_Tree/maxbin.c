#include "tree.h"
#include "elemtype.h"
#include <stdbool.h>
#include <stdlib.h>

static Node* InsertRec(Node *n, ElemType* e) {

	if (TreeIsEmpty(n))
	{
		return TreeCreateRoot(e, NULL, NULL);
	}

	if (ElemCompare(e, TreeGetRootValue(n)) <= 0)
	{
		n->left = InsertRec(e, TreeLeft(n));
	}
	else
	{
		n->right = InsertRec(e, TreeRight(n));
	}
	return n;

}

static Node* CreateMaxBinTreeRec(const ElemType* v, size_t v_size, size_t currIndex, Node* t, ElemType *val, int* quanti, size_t *index, bool *used, ElemType *v1, ElemType *v2) {

	/*if (TreeIsEmpty(t))
	{
		used[currIndex] = true;
		//*quanti += 1;
		return TreeCreateRoot(&val, NULL, NULL);
	}*/


	/*for (size_t i = 0; i < v_size; i++)
	{
		if (!used[i] && i < *index)
		{
			t->left = CreateMaxBinTreeRec(v, v_size, currIndex = i, TreeLeft(t), v[i], quanti, index, max, used);
		}
		if (!used[i] && i > *index)
		{
			t->right = CreateMaxBinTreeRec(v, v_size, currIndex = i, TreeRight(t), v[i], quanti, index, max, used);
		}
	}*/

	
	for (size_t i = 0; i < *index; i++)
	{
		//t->left = CreateMaxBinTreeRec(v, v_size, currIndex = i, TreeLeft(t), v[i], quanti, index, used, v1, v2);
		t->left = InsertRec(t, v1[i]);
	}
	
	*quanti += 1;

	if (*quanti >= *index)
	{
		for (size_t i = v_size; i > * index; i--)
		{
			if (!used[i])
			{
				//t->right = CreateMaxBinTreeRec(v, v_size, currIndex = i, TreeRight(t), v[i], quanti, index, used, v1, v2);
				t->right = InsertRec(t, &v[i]);
			}
		}
	}
	return t;
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {

	if (v == NULL || v_size == 0)
	{
		return NULL;
	}

	ElemType max = 0;
	size_t index = 0;
	int quanti = 0;
	ElemType val = 0;
	bool* used = calloc(v_size, sizeof(bool));

	for (size_t i = 0; i < v_size; i++)
	{
		if (v[i] > max)
		{
			max = v[i];
			index = i;
		}
	}
	Node* ris = TreeCreateRoot(&max, NULL, NULL);
	used[index] = true;

	ElemType* v1 = calloc(index, sizeof(ElemType));
	ElemType* v2 = calloc((v_size - index), sizeof(ElemType));


	for (size_t i = 0; i < index; i++)
	{
		v1[i] = v[i];
	}

	for (size_t i = v_size; i > index; i--)
	{
		v2[i] = v[i];
	}

	CreateMaxBinTreeRec(v, v_size, 0, ris, val, &quanti, &index, used, v1, v2);

	return ris;

}
