#include <unistd.h>
#include <stdio.h>

int	g_arr[15];
int	g_count = 0;
//int 	g_map[15][15];
int 	k;
/*
void 	g_arr_gen(int n, int j)
{
	while (j < k)
	{
		if (g_map[n][j - 1])
		{
			//printf("in gen, g_map[%d][%d] = %d\n", n, j - 1, g_map[n][j - 1]);
			j = j + 1;
		}
		else
		{
			g_arr[n] = j;
			return ;
		}
	}
	return ;
}

void 	push_g_map(int n)
{
	int i = 1;
	int temp = g_arr[n];
//	printf("temp : %d\n", g_arr[n]);
	while (++n <= k - 1)
	{
		g_map[n][temp - 1] = 1;
//		printf("in push, g_map[%d][%d] = 1\n", n, temp - 1);
		g_map[n][temp - 1 + i] = 1;
//		printf("in push, g_map[%d][%d] = 1\n", n, temp - 1 + i);
		g_map[n][temp - 1 - i] = 1;
//		printf("in push, g_map[%d][%d] = 1\n", n, temp - 1 - i);
		i++;
	}	
}

void	pop_g_map(int n)
{
	int i = 0;
	n++;
	while (n <= k - 1)
	{
		g_map[n][i++] = 0;
//		printf("in pop, g_map[%d][%d] = 0\n", n, i - 1);
		if(i == k - 1)
		{
			i = 0;
			n++;
		}
	}
}
*/
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
	while (j <= k)
	{
//		g_arr_gen(n, j);
		g_arr[n] = j;
		printf("trial g_arr[%d] = %d\n", n, j);
		if (promising(n))
//		if (promising(n) && !g_map[i][j - 1])
		{
//			printf("g_map[%d][%d] = %d\n", n, j - 1, g_map[n][j - 1]);
			printf("confirm\n");
			if (n == k - 1)
			{
				g_count++;
				while (i < k)
				{
					printf("result : %d", g_arr[i]);
					i++;
				}
				i = 0;
				printf("\n");
			}
			else
			{
				//printf("push_g_map(%d)\n", n);
//				push_g_map(n);
				checknode(n + 1);
				//printf("pop_g_map(%d)\n", n);
//				pop_g_map(n);
			}
		}
		j++;
	
	}
}

int main(void) 
{
	scanf("%d", &k);
	checknode(0);
	printf("%d\n", g_count);
	return (0);
}
