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

void	binary_search(int *arr, int size, int key)
{
	int start = 0;
	int end = size - 1;
	int mid;

	while (end - start >= 0)
	{	
		mid = (end + start)/2;
		if (arr[mid] == key)
		{
			printf("1 ");
			return ;
		}
		else if (arr[mid] < key)
			start = mid + 1;
		else
			end = mid - 1;
	}
	printf("0 ");
	return ;
}

int	main(void)
{
	int i;
	int *arr;
	int n;
	int j;
	int num;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &j);
	for(i = 0; i < j; i++)
	{
		scanf("%d", &num);
		binary_search(arr, n, num);
	}
	free(arr);
	return (0);
}
