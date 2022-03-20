/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:26:36 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 22:26:41 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	sa(t_stack *s)
{
	int	swap;

	if (s->nb_a > 1)
	{
		swap = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = swap;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	int	swap;

	if (s->nb_b > 1)
	{
		swap = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = swap;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *s)
{
	sa(s);
	sb(s);
	write(1, "ss\n", 3);
}
