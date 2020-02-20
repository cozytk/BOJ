#include <unistd.h>
#include <stdio.h>

char	g_arr[3];

int	promising(int n)
{
	int i = 0;

	while (i < n)
	{
		if (g_arr[i] == g_arr[n])
			return (0);
		else if (g_arr[i] == g_arr[n] + (n - i) || g_arr[i] == g_arr[n] - (n - i))
			return (0);
		i++;
	}
	return (1);
}
	 

void	checknode(int n)
{
	int i = 0;
	int j = 1;
	while (j <= 4)
	{
		g_arr[n] = j;
		printf("try g_arr[%d] = %d\n", n, j);
		if (promising(n))
		{
			printf("confirm arr[%d] = %d\n", n, j);
			if (n == 3)
			{
				while (i <= 3)
					printf("result is %d\n", g_arr[i++]);
			}
			else
				checknode(n + 1);
		}
		j++;
	
	}
}

int main(void) 
{
	checknode(0);
	return (0);
}
