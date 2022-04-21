#include "elemtype.h"
#include "tree.h"

int CountDominantRec(const Node* t, int *quanti) {

	//se è foglia non ha figli da controllare
	if (TreeIsLeaf(t))
	{
		return;
	}

	if (!TreeIsEmpty(TreeLeft(t)) && !TreeIsEmpty(TreeRight(t)))
	{
		Node* l = TreeLeft(t);
		Node* r = TreeRight(t);

		if (t->value > (l->value + r->value))
		{
			*quanti += 1;
		}
	}

	CountDominantRec(TreeLeft(t), quanti);
	CountDominantRec(TreeRight(t), quanti);

}

int CountDominant(const Node* t) {

	int quanti = 0;
	CountDominantRec(t, &quanti);
	return quanti;

}