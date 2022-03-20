/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:03:11 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 23:03:13 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../../include/push_swap.h"

int	find_smallest_a(t_stack *s)
{
	int	i;
	int	res;
	int	tmp;

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
