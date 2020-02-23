#include <stdio.h>

int	main(void)
{
	int n;
	int arr[2001] = { 0, };
	int num;
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num + 1000] = 1;
	}
	for (i = 0; i < 2001; i++)
	{
		if (arr[i] == 1)
			printf("%d\n", i - 1000);
	}
	return (0);
}

