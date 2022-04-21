#include "stdio.h"

void Back(int n, int i, int k, int* vcurr, int* nsol) {

    if (i == n) {
        printf("%d) ", *nsol);
        (*nsol)++;
        for (int j = 0; j < n; j++) {
            printf("%d ", vcurr[j]);
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < k; j++) {
        vcurr[i] = j;
        Back(n, i + 1, k, vcurr, nsol);
    }
}

int main(void) {

    int n  = 0;
    int v[4] = { 0, 0, 0, 0 };
    Back(4, 0, 5, v, &n);

}