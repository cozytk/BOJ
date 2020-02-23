#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int	binary_search(int *arr, int size, int key)
{
	int start = 0;
	int end = size - 1;
	int mid;

	while (end - start >= 0)
	{	
		mid = (end - start)/2;
		if (arr[mid] == key)
			return 1;
		else if (arr[mid] > key)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}

int	main(void)
{
	int i;
	int *arr;
	int n;
	int j;
	int *cmp;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	printf("sorted array :");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	scanf("%d", &j);
	cmp = (int *)malloc(sizeof(int) * j);
	for(i = 0; i < j; i++)
		scanf("%d", &cmp[i]);
	printf("the arr cmp :");
	for(i = 0; i < j; i++)
		printf("%d ", cmp[i]);
	printf("\n");
	for(i = 0; i < j; i++)
	{
		printf("binary_search(arr, %d, %d)\n", n, cmp[i]);
		binary_search(arr, n, cmp[i]);
			printf("1 ");
		else
			printf("0 ");
	}
	free(arr);
	free(cmp);
	return (0);
}
