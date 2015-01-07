#include <stdio.h>
#include <stdlib.h>

void
Input(int* size, int** arr)
{
	puts("Enter the number of the array: ");
	scanf("%d", size);
	if (*size == 0)
		return;
	*arr = (int*)malloc(sizeof(int)*(*size));
	puts("Enter ervery number of the array: ");
	int i = 0;
	do {
		scanf("%d", &(*arr)[i]);
	} while(++i < *size);
}

void
Output(int size, int* arr)
{
	int i = 0;
	while (i < size) {
		printf("%d  ", arr[i]);
		i++;
	}
}

void
Partition(int begin, int end, int* arr)
{
	if (begin >= end)
		return;
	int first = begin - 1;
	int second = begin;
	int pivort = arr[end];
	while (second <= end) {
		if (arr[second] <= pivort) {
			first++;
			int temp = arr[second];
			arr[second] = arr[first];
			arr[first] = temp;
		}
		second++;
	}
	Partition(begin, first-1, arr);
	Partition(first+1, end, arr);
}

int
main(int argc, char** argv)
{
	int* arr;
	int size;
	Input(&size, &arr);
	Partition(0, size-1, arr);
	Output(size, arr);
	return 0;
}
