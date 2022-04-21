#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int cnt, int* nsol) {
	if ((cnt) == k) {
		(*nsol)++;
		printf("%d) ", (*nsol));
		for (int j = 0; j < n; j++) {
			if (vcurr[j]) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	if (i == n) {

		return;
	}
	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);
	vcurr[i] = 1;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
}

int Ombrelloni(int k, int n) {
	if (k < 0 && n < 0)return 0;
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	int cnt = 0;
	OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
	return nsol;
}

int main(void) {
	Ombrelloni(2, 4);

}