#include "../include/push_swap.h"

int	check_if_right(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (s->nb_a == 1)
		return (0);
	while (i < (s->nb_a - 1))
	{
		j = i + 1;
		while ((s->stack_a[i] < s->stack_a[j]) && (j < s->nb_a))
			j++;
		if (s->stack_a[i] < s->stack_a[j - 1])
			i++;
		else
			return (1);
	}
	if (i == s->nb_a - 1)
		return (0);
	return (1);
}

void	push_swap(t_stack *s)
{
	if (check_if_right(s) == 0)
		return ;
	if (s->nb_a == 2)
		sa(s);
	if (s->nb_a == 3)
		three_algo(s);
	else if (s->nb_a <= 5)
		five_algo(s);
	else
		new_algo(s);
}