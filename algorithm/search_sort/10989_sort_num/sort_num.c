#include <stdio.h>

int	main(void)
{
	int	arr[10001] = { 0, };
	int n;
	int i;
	int num;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}
	for (i = 1; i < 10001; i++)
	{
		while (arr[i] > 0)
		{
			printf("%d\n", i);
			arr[i]--;
		}
	}
	return (0);
}
