/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:03:29 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 23:03:31 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

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

	i = find_smallest_a(s);
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
