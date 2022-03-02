#include "../../include/push_swap.h"

void	sa(t_stack *s)
{
	int	swap;

	if (s->nb_a > 1)
	{
		swap = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = swap;
	}
	printf("sa\n");
}

void	sb(t_stack *s)
{
	int	swap;

	if (s->nb_b > 1)
	{
		swap = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = swap;
	}
	printf("sb\n");
}

void	ss(t_stack *s)
{
	sa(s);
	sb(s);
	printf("ss\n");
}