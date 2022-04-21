#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* TreeReadRec(Node* t, char *in, int index, int *used) {

	if (in[index] == '.')
	{
		t = TreeCreateRoot(in[index-1], NULL, NULL);
		return t;
	}

	if (used[index] == 0)
	{
		used[index] == 1;
		t->left = TreeReadRec(TreeLeft(t), in, index + 1, used);
		used[index] == 0;
	}
	if (used[index] == 0)
	{
		used[index] == 1;
		t->right = TreeReadRec(TreeRight(t), in, index + 1, used);
		used[index] == 0;
	}

	return t;

}

Node* TreeRead(const char* filename) {

	FILE *f = fopen(filename, "r");

	if (f == NULL)
	{
		return TreeCreateEmpty();
	}

	char* in = malloc(sizeof(char));
	char c = "";
	int quanti = 0;

	while (true)
	{
		c = fgetc(f);
		if (c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != '\v' && c != '\f')
		{
			++quanti;
			in = realloc(in, sizeof(char) * quanti);
			in[quanti - 1] = c;
		}
		if (c == EOF)
		{
			break;
		}
	}


	ElemType e = (int)in[0];
	Node* ris = TreeCreateRoot(&e, NULL, NULL);

	int* used = calloc(quanti, sizeof(int));

	TreeReadRec(ris, in, 0, used);

}