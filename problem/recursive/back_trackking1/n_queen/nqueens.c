#include <stdio.h>
#include <unistd.h>

int	g_arr[15];
int	g_pos[15][15];
int	g_count = 0;
int	k;

int	promising(int new)
{
	int ext = 0;
	int diff;

	while (ext < new)
	{
		diff = new - ext;
		printf("g_arr[%d] : %d\n", new, g_arr[new]);
		printf("g_arr[%d] : %d\n", ext, g_arr[ext]);
		printf("diff : %d\n", diff);
		if (g_arr[new] == g_arr[ext])
			return (0);
		else if ((g_arr[new] == g_arr[ext] - diff) || (g_arr[new] == g_arr[ext] + diff))
			return (0);
		ext++;
	}
	return (1);
}


void	checknode(int row)
{
	int col = 0;

	if (row == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d\n", g_arr[i]);
		g_count++;
	}
	else
	{
		while (col < k)
		{
			g_arr[row] = col;
			printf("tiral g_arr[%d] = %d\n", row, col);
			if (promising(row))
			{
				printf("confirm\n");
				checknode(row + 1);
			}
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
