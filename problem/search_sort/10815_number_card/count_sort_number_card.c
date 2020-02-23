#include <stdio.h>

int	main(void)
{
	int i;
	char arr[20000001] = { 0, };
	int n;
	int num;
	int cnt = 0;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num + 10000000] = 1;
	}
	scanf("%d", &n);
	for (i = 0; i < 20000001; i++)
	{
		scanf("%d", &num);
		if (arr[num + 10000000])
			printf("1 ");
		else
			printf("0 ");
	}
	return (0);
}
