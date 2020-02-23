#include <unistd.h>
#include <stdio.h>

int	g_arr[15];
int	g_count = 0;
int 	g_map[15][15];
int 	k;

void	push_g_map(int n);
void 	pop_g_map(int n);

int 	g_arr_gen(int n, int *j)
{
	while (++(*j) < k)
	{
		if (g_map[n][*j])
		{
			printf("in gen, g_map[%d][%d] = %d\n", n, *j, g_map[n][*j]);
		}
		else
		{
			g_arr[n] = *j;
			push_g_map(n);
			return (1);
		}
	}
	pop_g_map(n);
	return (0);
}

void 	push_g_map(int n)
{
	int i = 1;
	int temp = g_arr[n];
	printf("temp : %d\n", g_arr[n]);
	while (++n < k)
	{
		g_map[n][temp] = 1;
		printf("in push, g_map[%d][%d] = 1\n", n, temp);
		g_map[n][temp + i] = 1;
		printf("in push, g_map[%d][%d] = 1\n", n, temp + i);
		g_map[n][temp - i] = 1;
		printf("in push, g_map[%d][%d] = 1\n", n, temp - i);
		i++;
	}	
}


void	pop_g_map(int n)
{
	int i = 0;
	while (n < k)
	{
		while (i < k)
		{
			g_map[n][i++] = 0;
			printf("in pop, g_map[%d][%d] = 0\n", n, i);
		}
		n++;
	}
}

void	checknode(int row)
{
	int col = -1; 
	if (row == k)
	{	
		for (int i = 0; i < k; i++)
			printf("result g_arr[%d] = %d\n", i, g_arr[i]);
		g_count++;
	}
	else
	{
		while (col < k)
		{
			if(g_arr_gen(row, &col))
			{
				for (int i = 0; i <= row; i++)
					printf("g_arr[%d] = %d\n", i, g_arr[i]);
				checknode(row + 1);
			}
			col++;
		}
	}
}

int main(void) 
{
	scanf("%d", &k);
	checknode(0);
	printf("%d\n", g_count);
	return (0);
}
