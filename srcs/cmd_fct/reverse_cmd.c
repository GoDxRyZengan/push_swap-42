#include "../../include/push_swap.h"

void	rra(t_stack *s)
{
	int	swap;
	int	i;

	i = s->nb_a - 1;
	if (s->nb_a > 1)
	{
		swap = s->stack_a[i];
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = swap;
	}
	printf("rra\n");
}

void	rrb(t_stack *s)
{
	int	swap;
	int	i;

	i = s->nb_b - 1;
	if (s->nb_b > 1)
	{
		swap = s->stack_b[i];
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = swap;
	}
	printf("rrb\n");
}

void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
	printf("rrr\n");
}