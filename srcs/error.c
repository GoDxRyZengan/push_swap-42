#include "../include/push_swap.h"

void	error(int i)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (i == 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

