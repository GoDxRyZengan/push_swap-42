#include "../../include/push_swap.h"

void	pa(t_stack *s)
{
	int	*swap_a;
	int	*swap_b;
	int	i;
	
	i = 0;
	if (s->nb_b != 0)
	{
		swap_a = create_stack(s->nb_a + 1);
		swap_b = create_stack(s->nb_b - 1);
		swap_a[0] = s->stack_b[0];
		while (i < s->nb_a)
		{
			swap_a[i + 1] = s->stack_a[i];
			i++;
		}
		s->nb_a = i + 1;
		i = 0;
		while (i < s->nb_b - 1)
		{
			swap_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->nb_b = i;
		free(s->stack_a);
		free(s->stack_b);
		s->stack_a = swap_a;
		s->stack_b = swap_b;
	}
	printf("pa\n");
}

void	pb(t_stack *s)
{
	int	*swap_a;
	int	*swap_b;
	int	i;
	
	i = 0;
	if (s->nb_a != 0)
	{
		swap_a = create_stack(s->nb_a - 1);
		swap_b = create_stack(s->nb_b + 1);
		swap_b[0] = s->stack_a[0];
		while (i < s->nb_b)
		{
			swap_b[i + 1] = s->stack_b[i];
			i++;
		}
		s->nb_b = i + 1;
		i = 0;
		while (i < s->nb_a - 1)
		{
			swap_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->nb_a = i;
		free(s->stack_a);
		free(s->stack_b);
		s->stack_a = swap_a;
		s->stack_b = swap_b;
	}
	printf("pb\n");
}