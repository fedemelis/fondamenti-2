#include <stdio.h>
#include <stdlib.h>

void ProcA(int a, int b, int* c) {
    int d = a + 1;
    a = b - 2;
    *c = b;
    b = (*c) - d;
}

char FunzB(int a1, int* a2) {
    int* a3 = malloc(sizeof(int));
    *a3 = (*a2);
    ProcA(a1, *(a2), a3);
    printf("a1:%d, a2:%d, a3:%d\n", a1, *a2, *a3);
    return *a3;
}

int main(void) {
    int a = 3, b = 4, c = 0;
    for (int i = 0; i < 3; i += 2)
        c += FunzB(a++, &b);
    printf("a:%d, b:%d, c:%d \n", a, b, c);
    return 0;
}