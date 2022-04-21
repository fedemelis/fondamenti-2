#include <stdlib.h>

int Minimo(const int* v, int v_size) {

	if (v_size <= 0)
	{
		return v[0];
	}

	int min = 999999;
	int index = 0;
	int* newV = malloc(sizeof(int) * v_size);

	for (int i = 0; i < v_size; i++)
	{
		newV = v;
		if (newV[i] < min)
		{
			min = newV[i];
			index = i;
		}
	}
	newV[0] = newV[index];

	Minimo(v, v_size - 1);

}


int main(void) {

	int v[] = { 5, 3, 5, 1, 2 };

	int ris = Minimo(v, 5);


}