#include "../../include/push_swap.h"

int	check_smaller(t_stack *s, int j)
{
	int	i;

	i = 0;
	if (i == j)
			i++;
	while (s->stack_a[j] < s->stack_a[i] && (i < s->nb_a))
	{
		if (i + 1 == j)
			i++;
		i++;
	}
	if (i == s->nb_a)
		return (0);
	return (1);
}

void	three_algo(t_stack *s)
{
	if ((s->stack_a[1] > s->stack_a[0]) && (s->stack_a[1] > s->stack_a[2]))
	{
		rra(s);
		if (check_if_right(s) == 1)
			sa(s);
	}
	else if ((s->stack_a[0] > s->stack_a[1]) && (s->stack_a[0] > s->stack_a[2]))
	{
		ra(s);
		if (check_if_right(s) == 1)
			sa(s);
	}
	else if (s->stack_a[0] > s->stack_a[1])
		sa(s);
}

void	push_smaller(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->nb_a)
	{
		if (check_smaller(s, i) == 0)
			break;
		i++;
	}
	if (i < 3 && s->nb_a)
	{
		while (i != 0)
		{
			ra(s);
			i--;
		}
		pb(s);
	}
	else
	{
		while (i < s->nb_a)
		{
			rra(s);
			i++;
		}
		pb(s);
	}
}

void	five_algo(t_stack *s)
{
	push_smaller(s);
	push_smaller(s);
	three_algo(s);
	if (s->stack_b[0] < s->stack_b[1])
		sb(s);
	pa(s);
	pa(s);
}