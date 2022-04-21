#include <stdlib.h>

void flip(int* v, size_t curr_size) {

	int left = 0;
	while(curr_size > left)
	{
		int tmp = v[curr_size];
		v[curr_size] = v[left];
		v[left] = tmp;
		--curr_size;
		++left;
	}
}

void PancakeSort(int* v, size_t v_size) {

	if (v == NULL || v_size <= 0)
	{
		return;
	}

	int max = -99999999;
	size_t index = 0;

	for (size_t i = v_size; v_size > 1; v_size--)
	{
		for (size_t i = 0; i < v_size; i++)
		{
			if (max < v[i])
			{
				max = v[i];
				index = i;
			}
		}

		flip(v, index);
		flip(v, v_size - 1);
		max = -99999999;
	}
}