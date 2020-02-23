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

int	main(void)
{
	int n;
	int *arr;
	int i;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	free(arr);
	return (0);
}
