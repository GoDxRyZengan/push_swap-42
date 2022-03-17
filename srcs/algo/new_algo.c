#include "./../../include/push_swap.h"

int	find_biggest(t_stack *s, int index, int k)
{
	int	i;
	int	tmp;
	int	res;

	tmp = s->stack_b[k];
	res = k;
	i = 0;
	while (i < s->nb_b)
	{
		if ((s->stack_a[index] > s->stack_b[i]) && (tmp < s->stack_b[i]))
		{
			tmp = s->stack_b[i];
			res = i;
		}
		i++;
	}
	return (res);
}

int	find_smallest(t_stack *s)
{
	int i;
	int	res;
	int tmp;

	tmp = s->stack_b[0];
	res = 0;
	i = 0;
	while (i < s->nb_b)
	{
		if (s->stack_b[i] < tmp)
		{
			tmp = s->stack_b[i];
			res = i;
			i = 0;
		}
		else
			i++;
	}
	return (res);
}

int	m_to_r_b(t_stack *s, int index)
{
	int	i;

	i = 0;
	while (i < s->nb_b)
	{
		if (s->stack_a[index] > s->stack_b[i])
		{
			i = find_biggest(s, index, i);
			break;
		}
		i++;
	}
	if (s->nb_b == i)
	{
		i = find_smallest(s);
		if (i > s->nb_b / 2)
		{
			i = s->nb_b - i - 1;
			s->tmp = 'c';
		}
		else
		{
			i++;
			s->tmp = 'd';
		}
	}
	else if (i > s->nb_b / 2)
	{
		i = s->nb_b - i;
		s->tmp = 'b';
	}
	else
		s->tmp = 'a';
	return (i);
}

void	who_to_m_b(t_stack *s)
{
	int	i;

	i = 0;
	s->m = i + m_to_r_b(s, i);
	s->to_m = i;
	s->how = s->tmp;
	while (i < s->nb_a)
	{
		if (i < (s->nb_a / 2))
		{
			if (s->m > (i + m_to_r_b(s, i)))
			{
				s->m = i + m_to_r_b(s, i);
				s->to_m = i;
				s->how = s->tmp;
			}
		}
		else
		{
			if (s->m > ((s->nb_a - i) + m_to_r_b(s, i)))
			{
				s->m = (s->nb_a - i) + m_to_r_b(s, i);
				s->to_m = i;
				s->how = s->tmp;
			}
		}
		i++;
	}
}

void	a_move(t_stack *s)
{
	if (s->to_m < (s->nb_a / 2))
	{
		while (s->to_m > 0)
		{
			ra(s);
			s->to_m--;
			s->m--;
		}
	}
	else
	{
		while (s->to_m < s->nb_a)
		{
			rra(s);
			s->to_m++;
			s->m--;
		}
	}
	while (s->m > 0)
	{
		rb(s);
		s->m--;
	}
	pb(s);
}

void	b_move(t_stack *s)
{
	if (s->to_m < (s->nb_a / 2))
	{
		while (s->to_m > 0)
		{
			ra(s);
			s->to_m--;
			s->m--;
		}
	}
	else
	{
		while (s->to_m < s->nb_a)
		{
			rra(s);
			s->to_m++;
			s->m--;
		}
	}
	while (s->m > 0)
	{
		rrb(s);
		s->m--;
	}
	pb(s);
}

void	c_move(t_stack *s)
{
	if (s->to_m < (s->nb_a / 2))
	{
		while (s->to_m > 0)
		{
			ra(s);
			s->to_m--;
			s->m--;
		}
	}
	else
	{
		while (s->to_m < s->nb_a)
		{
			rra(s);
			s->to_m++;
			s->m--;
		}
	}
	while (s->m > 0)
	{
		rrb(s);
		s->m--;
	}
	pb(s);
}

void	d_move(t_stack *s)
{
	if (s->to_m < (s->nb_a / 2))
	{
		while (s->to_m > 0)
		{
			ra(s);
			s->to_m--;
			s->m--;
		}
	}
	else
	{
		while (s->to_m < s->nb_a)
		{
			rra(s);
			s->to_m++;
			s->m--;
		}
	}
	while (s->m > 0)
	{
		rb(s);
		s->m--;
	}
	pb(s);
}

int	find_smallest_a(t_stack *s)
{
	int i;
	int	res;
	int tmp;

	tmp = s->stack_a[0];
	res = 0;
	i = 0;
	while (i < s->nb_a)
	{
		if (s->stack_a[i] < tmp)
		{
			tmp = s->stack_a[i];
			res = i;
			i = 0;
		}
		else
			i++;
	}
	return (res);
}

void	new_algo(t_stack *s)
{
	int i;

	pb(s);
	print_stack(s);
	while (s->nb_a > 0)
	{
		s->m = 0;
		who_to_m_b(s);
		if (s->how == 'a')
			a_move(s);
		else if (s->how == 'c')
			c_move(s);
		else if (s->how == 'd')
			d_move(s);
		else
			b_move(s);
	}
	while (s->nb_b > 0)
		pa(s);
	i = find_smallest_a(s);
	if (i < (s->nb_a / 2))
	{
		while (i > 0)
		{
			ra(s);
			i--;
		}
	}
	else
	{
		while (i < s->nb_a)
		{
			rra(s);
			i++;
		}
	}
	print_stack(s);
}