#include <stdio.h>

int	main(void)
{
	long long min;
	long long max;
	int cnt = 0;
	long long i;
	long long k;
	_Bool arr[1000001] = { 0, };

	scanf("%lld %lld", &min, &max);

	for (i = 2; i * i <= max; i++)
	{
		k = min / (i * i);
		if (k * i * i != min)
			k++;
		while (k * (i * i) <= max)
		{
			arr[k * (i * i) - min] = 1;
			k++;
		}
	}

	for (i = 0; i <= max - min; i++)
	{
		if (!arr[i])
			cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}

//why do I change the type make the result different?
