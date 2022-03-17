#include "./../../include/push_swap.h"

void		l_m_r(t_stack *s)
{
	int	m;
	int	i;
	int	j;

	m = 10000;
	i = 0;
	s->r.c = 115;
	s->r.max = 0;
	while (i < s->nb_b)
	{
		j = 0;
		if (s->stack_b[i] < s->stack_a[j])
		{
			if ((i > (s->nb_b / 2)) && (m > (s->nb_b - i + 1)))
			{
				m = (s->nb_b - i) + 1;
				s->r.ind = i;
				s->r.c = 97;
			}
			else if (m > (i + 1))
			{
				m = i + 1;
				s->r.ind = i;
				s->r.c = 98;
			}
		}
		else
		{
			while ((s->stack_b[i] > s->stack_a[j]) && (j < s->nb_a))
				j++;
			if (j > (s->nb_a / 2))
			{
				if ((i > (s->nb_b / 2)) && (m > (s->nb_a - j + s->nb_b - i + 2)))
				{
					m = (s->nb_a - j + s->nb_b - i + 2);
					s->r.ind = i;
					s->r.max = j;
					s->r.c = 99;
				}
				else if (m > ((s->nb_a - j) + i + 2))
				{
					m = (s->nb_a - j + i + 2);
					s->r.ind = i;
					s->r.max = j;
					s->r.c = 100;
				}
			}
			else
			{
				if ((i > (s->nb_b / 2)) && (m > (s->nb_a - j + i + 2)))
				{
					m = (s->nb_a - j + i + 2);
					s->r.ind = i;
					s->r.max = j;
					s->r.c = 101;
				}
				else if (m > (j + i + 1))
				{
					m = j + i;
					s->r.ind = i;
					s->r.max = j;
					s->r.c = 102;
				}
			}
		}
		i++;
	}
}

void		l_m_t(t_stack *s)
{
	int	m;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s->stack_a[i] != s->r.right[0])
		i++;
	if (i <= (s->nb_a / 2))
	{
		m = i;
		s->r.ind = i;
	}
	else
	{
		m = s->nb_a - i;
		s->r.ind = i;
	}
	while ((j <= s->nb_a / 2) && (j < (s->r.nb - 2)))
	{
		i = 0;
		while (s->stack_a[i] != s->r.right[j])
			i++;
		if (i <= (s->nb_a / 2))
		{
			if (m > i)
			{
				m = i;
				s->r.ind = i;
			}
		}
		else
		{
			if (m > (s->nb_a - i))
			{
				m = s->nb_a - i;
				s->r.ind = i;
			}
		}
		j++;
	}
}

void	do_right(t_stack *s)
{
	int	i;
	int	swap;

	s->r.nb = s->nb_a;
	i = 0;
	s->r.right = create_stack(s->nb_a);
	while (i < s->nb_a)
	{
		s->r.right[i] = s->stack_a[i];
		i++;
	}
	i = 0;
	while (i < s->r.nb - 1)
	{
		if (s->r.right[i] > s->r.right[i + 1])
		{
			swap = s->r.right[i];
			s->r.right[i] = s->r.right[i + 1];
			s->r.right[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void	quick_push(t_stack *s)
{
	if (s->r.ind <= (s->nb_a / 2))
	{
		while (s->r.ind > 0)
		{
			ra(s);
			s->r.ind--;
		}
	}
	else
	{
		while (s->r.ind <= s->nb_a)
		{
			rra(s);
			s->r.ind++;
		}
	}
	pb(s);
}

void	hundred_algo(t_stack *s)
{
	while (s->nb_a > 3)
	{
		do_right(s);
		l_m_t(s);
		quick_push(s);
		free(s->r.right);
	}
	three_algo(s);
	pb(s);
	while (s->nb_b > 0)
	{
		l_m_r(s);
//		print_stack(s);
//		printf("INFO :%d / %d / %c\n", s->r.ind, s->r.max, s->r.c);
		if (s->r.c == 'a')
			do_a(s);
		if (s->r.c == 'b')
			do_b(s);
		if ((s->r.c == 'c') || (s->r.c == 'e'))
			do_c_e(s);
		if ((s->r.c == 'd') || (s->r.c == 'f'))
			do_d_f(s);
	}
//	print_stack(s);
}