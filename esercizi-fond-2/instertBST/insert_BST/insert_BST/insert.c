#include "elemtype.h"
#include "tree.h"

Node* BstInsertRec(const ElemType* e, Node* n) {

	/*
	* il caso base è treeIsEmpty. 
	* confronto il valore di e con il nodo che sto analizzando, se e è più piccolo rifaccio la chiamata ricorsiva sul sottoalbero sinistro e assegno il risultato
	* al left di n. 
	* n->left quando faccio la chiamata ricorsiva ho due possibili output: un nuovo nodo senza figli con valore "e", oppure n. Aseegnando ogni volta il risultato
	* della chiamata al nodo che sto esplorando fa si che, o inserisco il nuovo nodo nel figlio che è precedentemente vuoto, oppure riassegno il ciò che già c'è 
	* nel nodo al nodo.
	*/


	if (TreeIsEmpty(n))
	{
		//se vuoto creo, ritorno e assegno al ramo che sto esplorando
		return TreeCreateRoot(e, NULL, NULL);
	}

	//scelta percorso
	if (ElemCompare(e, TreeGetRootValue(n)) <= 0)
	{
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else
	{
		n->right = BstInsertRec(e,TreeRight(n));
	}
	//se il ramo che esploro non è null, ritorno n per assegnare a left o a right il loro stesso valore.z
	return n;

}

Node* BstInsert(const ElemType* e, Node* n) {
	return n = BstInsertRec(e, n);
}
