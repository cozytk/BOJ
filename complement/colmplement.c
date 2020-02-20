#include <stdio.h>

int main(void)
{
	int a = 2147483647;
	int b = ~a + 1;

	printf("b : %d\n", b);
}
