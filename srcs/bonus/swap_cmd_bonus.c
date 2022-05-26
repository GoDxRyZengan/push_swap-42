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

void	bonus_sa(t_stack *s)
{
	int	swap;

	if (s->nb_a > 1)
	{
		swap = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = swap;
	}
}

void	bonus_sb(t_stack *s)
{
	int	swap;

	if (s->nb_b > 1)
	{
		swap = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = swap;
	}
}

void	bonus_ss(t_stack *s)
{
	bonus_sa(s);
	bonus_sb(s);
}
