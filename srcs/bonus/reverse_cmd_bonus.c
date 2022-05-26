/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:02:28 by hucoulon          #+#    #+#             */
/*   Updated: 2022/05/26 19:02:31 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	bonus_rra(t_stack *s)
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
}

void	bonus_rrb(t_stack *s)
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
}

void	bonus_rrr(t_stack *s)
{
	bonus_rra(s);
	bonus_rrb(s);
}
