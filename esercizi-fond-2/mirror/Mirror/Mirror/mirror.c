#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>

bool TreeIsMirrorRec(Node* tL, Node *tR, bool * ris) {

	if (tL->right == NULL && tR->left == NULL && tL->left == NULL && tR->right == NULL)
	{
		return;
	}

	if ((tL->left == NULL && tR->right != NULL) || (tL->left != NULL && tR->right == NULL))
	{
		*ris = false;
		return;
	}

	if ((tL->right == NULL && tR->left != NULL) || (tL->right != NULL && tR->left == NULL))
	{
		*ris = false;
		return;
	}

	if (tL->right == NULL && tR->left == NULL)
	{
		return;
	}

	if (tL->left == NULL && tR->right == NULL)
	{
		return;
	}
	
	if (tL->left->value == tR->right->value && tL->right->value == tR->left->value)
	{
		TreeIsMirrorRec(TreeLeft(tL), TreeRight(tR), ris);
		TreeIsMirrorRec(TreeRight(tL), TreeLeft(tR), ris);
	}
	else
	{
		*ris = false;
		return;
	}

}

bool TreeIsMirror(Node* t) {

	if (TreeIsEmpty(t))
	{
		return true;
	}

	if (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t)))
	{
		return true;
	}

	bool ris = true;

	TreeIsMirrorRec(t, t, &ris);

	return ris;
}