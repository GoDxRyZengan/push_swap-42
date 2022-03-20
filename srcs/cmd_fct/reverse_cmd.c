/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:26:00 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 22:26:04 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	rra(t_stack *s)
{
	int	swap;
	int	i;

	i = s->nb_a - 1;
	if (s->nb_a > 1)
	{
		swap = s->stack_a[i];
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = swap;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s)
{
	int	swap;
	int	i;

	i = s->nb_b - 1;
	if (s->nb_b > 1)
	{
		swap = s->stack_b[i];
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = swap;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
	write(1, "rrr\n", 4);
}
