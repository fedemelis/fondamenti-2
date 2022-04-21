#include "elemtype.h"
#include "minheap.h"


ElemType KthLeast(const Heap* h, int k) {

	int quantiTrovati = 0;
	int min = 999999;
	int bestMin = 999999;
	int lastMin = -999999; 
	ElemType e = 0;

	if (k == 1)
	{
		for (size_t i = 0; i < h->size; i++)
		{
			if (h->data[i] < min && h->data[i] > lastMin)
			{
				min = h->data[i];
			}
		}
		e = min;
		min = 999999;
		return e;
	}

	for (size_t j = 0; j < k; j++)
	{
		for (size_t i = 0; i < h->size; i++)
		{
			if (h->data[i] < min && h->data[i] > lastMin)
			{
				min = h->data[i];
			}
		}
		lastMin = min;
		min = 999999;
	}

	e = lastMin;
	return e;
}