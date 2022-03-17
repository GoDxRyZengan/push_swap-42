#include "./../../include/push_swap.h"

void	do_a(t_stack *s)
{
	while (s->r.ind < s->nb_b)
	{
		rrb(s);
		s->r.ind++;
	}
	pa(s);
}

void	do_b(t_stack *s)
{
	while (s->r.ind > 0)
	{
		rb(s);
		s->r.ind--;
	}
	pa(s);
}

void	do_c_e(t_stack *s)
{
	int	i;

	i = 0;
	if (s->r.c == 'c')
	{
		while (s->r.max < s->nb_a)
		{
			rra(s);
			i++;
			s->r.max++;
		}
		i++;
		do_a(s);
		while (i > 0)
		{
			ra(s);
			i--;
		}
	}
	else
	{
		while (s->r.max > 0)
		{
			i++;
			ra(s);
			s->r.max--;
		}
		do_a(s);
		while (i > 0)
		{
			rra(s);
			i--;
		}
	}
}

void	do_d_f(t_stack *s)
{
	int	i;

	i = 0;
	if (s->r.c == 'd')
	{
		while (s->r.max < s->nb_a)
		{
			rra(s);
			i++;
			s->r.max++;
		}
		i++;
		do_b(s);
		while (i > 0)
		{
			ra(s);
			i--;
		}
	}
	else
	{
		while (s->r.max > 0)
		{
			ra(s);
			i++;
			s->r.max--;
		}
		do_b(s);
		while (i > 0)
		{
			rra(s);
			i--;
		}
	}
}