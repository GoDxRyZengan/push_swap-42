/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:17:29 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 23:17:38 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../../include/push_swap.h"

int	m_to_r_b(t_stack *s, int index)
{
	int	i;

	i = find_big(s, index);
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
				who_to_m_b_utils(s, i);
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

int	find_biggest_spe(t_stack *s, int index)
{
	int	i;
	int	tmp;
	int	res;

	res = -1;
	i = 0;
	tmp = 0;
	while (i < s->nb_b)
	{
		if (s->stack_a[index] > s->stack_b[i])
		{
			tmp = s->stack_b[i];
			res = i;
			break ;
		}
		i++;
	}
	if (res == -1)
	{
		res = find_smallest(s);
			res++;
	}
	else
		res = find_biggest_spe_utils(s, index, tmp, res);
	return (res);
}

void	new_algo(t_stack *s)
{
	int	i;

	pb(s);
	new_algo_utils(s);
	new_algo_utils_2(s);
	while (s->nb_b > 0)
		pa(s);
	i = find_smallest_a(s);
	s->how = s->tmp;
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
}
