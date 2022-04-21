#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
//#include "delete.h"

static Node* DeleteBstNodeRec(Node* n, const ElemType* key) {

	if (TreeIsEmpty(n)){
		return NULL;
	}

	if (ElemCompare(key, TreeGetRootValue(n)) < 0){
		n->left = DeleteBstNodeRec(TreeLeft(n), key);
	}
	else if (ElemCompare(key, TreeGetRootValue(n)) > 0){
		n->right = DeleteBstNodeRec(TreeRight(n), key);
	}
	else{
		if (TreeIsLeaf(n)){
			TreeDelete(n);
			return NULL;
		}

		if (TreeLeft(n) && TreeRight(n)){
			Node* predecessore;
			Node* tmp = TreeLeft(n);
			while (!TreeIsEmpty(TreeRight(tmp))){
				predecessore = TreeRight(tmp);
				tmp = TreeRight(tmp);
			}
			predecessore = tmp;
			ElemDelete(&tmp->value);
			ElemDelete(&n->value);
			n->value = ElemCopy(TreeGetRootValue(predecessore));
			n->left = DeleteBstNodeRec(TreeLeft(n), TreeGetRootValue(predecessore));
			return n;
		}

		else{
			Node* figlio;
			Node* tmp = n;
			if (TreeLeft(n)){
				figlio = TreeLeft(n);
			}
			else{
				figlio = TreeRight(n);
			}
			n = figlio;
			ElemDelete(&tmp->value);
			free(tmp);
			return n;
		}
	}
	return n;
}

Node* DeleteBstNode(Node* n, const ElemType* key) {

	n = DeleteBstNodeRec(n, key);
	return n;
}
