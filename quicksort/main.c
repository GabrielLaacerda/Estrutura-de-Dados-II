#include <stdio.h>
#include <stdlib.h>

void swap (int vector[], int a, int b)
{
	int temp = vector[a];
	vector[a] = vector[b];
	vector[b] = temp;
}

void quicksort(int vector[], int begin, int end)
{
	if (begin >= end)
		return;

	int i = begin;
	int j = end;

	int pivot = vector[(begin + end)/2];

	while (vector[i] < pivot)
		i = i + 1;

	while (vector[j] > pivot)
		j = j - 1;

	if (i <= j) {
		swap(vector, i, j);
		i++;
		j--;
	}

	quicksort(vector, begin, j);
	quicksort(vector, i, end);
}


int main()
{

	int vector[] = {2, 7, 3, 8, 4, 9, 1, 0, -1};
	int size = 9;

	int i;
	for (i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");

	quicksort(vector, 0, size);

	for (i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
	printf("\n");

	return 0;
}
