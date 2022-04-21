#include "elemtype.h"
#include "tree.h"

static void DiameterRec(const Node* t, int altezza, int *bestAltezza) {


	if (altezza > *bestAltezza && TreeIsLeaf(t))
	{
		*bestAltezza = altezza;
	}

	if (!TreeIsEmpty(TreeLeft(t)))
	{
		DiameterRec(TreeLeft(t), altezza + 1, bestAltezza);
	}
	if (!TreeIsEmpty(TreeRight(t)))
	{
		DiameterRec(TreeRight(t), altezza + 1, bestAltezza);
	}
	
	return;

	/*if (!TreeIsEmpty(TreeLeft(t)))
	{
		*bestAltezza += 1;
		DiameterRec(TreeLeft(t), altezza + 1, bestAltezza);
	}
	else if (!TreeIsEmpty(TreeRight(t)))
	{
		*bestAltezza += 1;
		DiameterRec(TreeRight(t), altezza + 1, bestAltezza);
	}

	return;*/

}

int Diameter(const Node* t) {

	if (TreeIsEmpty(t))
	{
		return 0;
	}

	int ris1 = 1;
	int ris2 = 1;
	DiameterRec(TreeLeft(t), 1, &ris1);
	DiameterRec(TreeRight(t), 1, &ris2);
	

	return (ris1 + ris2) + 1;
}