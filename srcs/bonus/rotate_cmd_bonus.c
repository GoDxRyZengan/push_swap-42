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

void	bonus_ra(t_stack *s)
{
	int	swap;
	int	i;

	i = 0;
	if (s->nb_a > 1)
	{
		swap = s->stack_a[0];
		while (i < s->nb_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[i] = swap;
	}
}

void	bonus_rb(t_stack *s)
{
	int	swap;
	int	i;

	i = 0;
	if (s->nb_b > 1)
	{
		swap = s->stack_b[0];
		while (i < s->nb_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->stack_b[i] = swap;
	}
}

void	bonus_rr(t_stack *s)
{
	bonus_ra(s);
	bonus_rb(s);
}
