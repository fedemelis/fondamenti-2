#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int *vCurr, int currentP, int quanti, int *quantiBest, bool *used, int index) {
	if (currentP >= p){
		if (currentP == p){
			*quantiBest = quanti;
			return;
		}
		else{
			vCurr[index] = 0;
			quanti -= 1;
			*quantiBest = quanti;
			return;
		}
	}
	int min = 99999;
	int indexMin = 0;
	for (int i = 0; i < pacchi_size; i++){
		if (pacchi[i] < min && used[i] == false){
			min = pacchi[i];
			indexMin = i;
		}
	}
	used[indexMin] = true;
	vCurr[indexMin] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, vCurr, currentP + pacchi[indexMin], quanti + 1, quantiBest, used, indexMin);
	return;
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if (p <= 0 || pacchi_size <= 0){
		return;
	}
	int* vCurr = calloc(pacchi_size, sizeof(int));
	bool* used = calloc(pacchi_size, sizeof(bool));
	int quantiBest = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vCurr, 0, 0, &quantiBest, used, 0);
	for (size_t i = 0; i < pacchi_size; i++){
		printf("%d ", vCurr[i]);
	}
	free(vCurr);
	free(used);
}