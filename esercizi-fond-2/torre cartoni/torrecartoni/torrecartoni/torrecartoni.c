#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n, Torre* vcurr, Torre *bestV, int* usati, int livello) {

	if (livello == n)
	{
		if (vcurr->altezzatot > bestV->altezzatot)
		{
			bestV->altezzatot = vcurr->altezzatot;
			bestV->pesotot = vcurr->pesotot	;
			bestV->size = vcurr->size;
			memcpy(bestV->pila, vcurr->pila, vcurr->size * sizeof(int));
			return;
		}
		
	}


	for (size_t i = 0; i < n; i++)
	{
		if (usati[i] != 1 && vcurr->pesotot <= c[i].l)
		{
			usati[i] = 1;
			vcurr->altezzatot += c[i].a;
			vcurr->pesotot += c[i].p;
			vcurr->size += 1;
			vcurr->pila[livello] = i;
			TorreCartoniRec(c, n, vcurr, bestV, usati, livello + 1);
			usati[i] = 0;
			vcurr->altezzatot -= c[i].a;
			vcurr->pesotot -= c[i].p;
			vcurr->size -= 1;
		}
	}
	if (vcurr->altezzatot > bestV->altezzatot)
	{
		bestV->altezzatot = vcurr->altezzatot;
		bestV->pesotot = vcurr->pesotot;
		bestV->size = vcurr->size;
		memcpy(bestV->pila, vcurr->pila, vcurr->size * sizeof(int));
		return;
	}



}

void TorreCartoni(const Cartone* c, size_t n) {

	Torre pila = { .pesotot = 0, .altezzatot = 0, .pila = calloc(n, sizeof(int)), 0};
	Torre pilamigliore = { .pesotot = 0, .altezzatot = 0, .pila = calloc(n, sizeof(int)), 0};
	int* used = malloc(n * sizeof(int));
	int stop_ = 0;
	int altezzatot = 0;

	TorreCartoniRec(c, n, &pila, &pilamigliore, used, 0);

	for (size_t i = 0; i < pilamigliore.size; i++)
	{
		printf("%d\n", pilamigliore.pila[i]);
	}
	printf("Altezza: %d", pilamigliore.altezzatot);

	free(pila.pila);
	free(pilamigliore.pila);
	free(used);

}