#include <stdio.h>
#include <math.h>

void	hanoi(int k, char a, char b, char c)
{
	if (k == 1)
		printf("%d %d\n", a, c);
	else
	{
		hanoi(k - 1, a, c, b);
		printf("%d %d\n", a, c);
		hanoi(k - 1, b, a, c);
	}
}

int	main(void)
{
	int k;
	unsigned long long cnt;

	scanf("%d", &k);
	cnt = pow(2, k) - 1; //finally, I used pow function
	printf("%lld\n", cnt);
	if (k <= 20)
		hanoi(k, 1, 2, 3);
	return(0);
}
