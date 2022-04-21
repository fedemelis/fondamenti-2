#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Node* TreeReadRec(char* c, Node* t, FILE* f, char* v, int i) {
	if (TreeRight(t) && TreeLeft(t))
		return t;
	*c = fgetc(f);
	if (*c == EOF)
		return t;
	if (*c == v[0] || *c == v[1] || *c == v[2] || *c == v[3] || *c == v[4] || *c == v[5])
		TreeReadRec(c, t, f, v, i);
	else if (*c != '.') {
		Node* figlioNodo = TreeCreateRoot(c, NULL, NULL);
		if (i == 1)t->left = figlioNodo, TreeReadRec(c, t->left, f, v, 1);
		else if (i == 2)t->right = figlioNodo, TreeReadRec(c, t->right, f, v, 1);

	}
	else if (*c == '.') {
		*c = fgetc(f);
		while ((*c == v[0] || *c == v[1] || *c == v[2] || *c == v[3] || *c == v[4] || *c == v[5])) {
			*c = fgetc(f);
		}
		Node* figlioNodo = TreeCreateRoot(c, NULL, NULL);
		if (i == 1)t->left = figlioNodo;
		else if (i == 2 || i == 3)t->right = figlioNodo;

		TreeReadRec(c, t, f, v, i + 1);
	}

	if ((TreeRight(t) && !TreeLeft(t)) || (!TreeRight(t) && TreeLeft(t)))
		TreeReadRec(c, t, f, v, i + 1);;
	return t;
}
extern Node* TreeRead(const char* filename) {

	FILE* f = fopen(filename, "rb");
	if (!f || fgetc(f) == EOF) {
		return TreeCreateEmpty();
	}
	rewind(f);
	char v[] = { ' ', '\t', '\r', '\n', '\v', '\f' };
	ElemType c;
	c = fgetc(f);

	if (c == '.') {
		c = fgetc(f);
		Node* t = TreeCreateRoot(&c, NULL, NULL);
		fclose(f);
		return t;
	}
	else {
		Node* t = TreeCreateRoot(&c, NULL, NULL);
		t = TreeReadRec(&c, t, f, v, 1);
		fclose(f);
		return t;
	}

}

//
//int main(void) {
//	TreeRead("albero1.txt");
//}