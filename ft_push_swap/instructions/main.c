#include <stdio.h>
#include "../push_swap.h"

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5};
	int i = 0;
	ra(arr);
	while (i < 5)
	{
		printf("%d", arr[i + 1]);
		i++;
	}
}
