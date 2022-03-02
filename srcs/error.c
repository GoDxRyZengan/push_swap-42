#include "../include/push_swap.h"

void	error(int i)
{
	if (i == 0)
	{
		printf("Error\nArg error\n");
		exit(1);
	}
	if (i == 1)
	{
		printf("Error\nNb error\n");
		exit(1);
	}
	if (i == 2)
	{
		printf("Error\n");
		exit(1);
	}
}

