#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else
		return 0;
}

void	binary_search(int *arr, int key, int len)
{
	int start = 0;
	int end = len - 1;
	int mid;

	while (end - start >= 0)
	{
		mid = (end + start)/2;
		if (arr[mid] == key)
		{
			printf("1\n");
			return ;
		}
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	printf("0\n");
	return ;
}

int	main(void)
{
	int i;
	int j = 0;
	int k;
	int* arr;
	int num;

	scanf("%d", &i);
	arr = (int *)calloc(i, sizeof(int));
	while (j < i)
	{
		scanf("%d", &arr[j]);
		j++;
	}
	qsort(arr, i, sizeof(int), compare);
	scanf("%d", &k);
	j = 0;
	while (j < k)
	{
		scanf("%d", &num);
		binary_search(arr, num, i);
		j++;
	}
	free(arr);
	return (0);
}
