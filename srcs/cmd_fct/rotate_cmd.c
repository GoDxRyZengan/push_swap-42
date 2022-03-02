#include "../../include/push_swap.h"

void	ra(t_stack *s)
{
	int	swap;
	int	i;

	i = 0;
	if (s->nb_a > 1)
	{
		swap = s->stack_a[0];
		while (i < s->nb_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[i] = swap;
	}
	printf("ra\n");
}

void	rb(t_stack *s)
{
	int	swap;
	int	i;

	i = 0;
	if (s->nb_b > 1)
	{
		swap = s->stack_b[0];
		while (i < s->nb_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->stack_b[i] = swap;
	}
	printf("rb\n");
}

void	rr(t_stack *s)
{
	ra(s);
	rb(s);
	printf("rr\n");
}