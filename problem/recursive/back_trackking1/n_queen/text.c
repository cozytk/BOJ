#include <stdio.h>
#include <stdlib.h>

int	g_arr[15];
int	g_count = 0;
int	k;

int	promising(int new)
{
	int att = 0;
	int diff;

	while (att < new)
	{
		diff = new - att;
		if (g_arr[new] == g_arr[att] || abs(g_arr[new] - g_arr[att]) == diff)
			return (0);
		att++;
	}
	return (1);
}

void	checknode(int row)
{
	int col = 0;

	if (row == k)
		g_count++;
	else
	{
		while (col < k)
		{
			g_arr[row] = col;
			if (promising(row))
				checknode(row + 1);
			col++;
		}
	}
}

			
int	main(void)
{
	scanf("%d", &k);
	checknode(0);
	printf("%d\n", g_count);
	return (0);
}
