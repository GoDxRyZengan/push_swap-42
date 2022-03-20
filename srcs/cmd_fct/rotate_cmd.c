/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:26:25 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 22:26:28 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	ra(t_stack *s)
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
	write(1, "ra\n", 3);
}

void	rb(t_stack *s)
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *s)
{
	ra(s);
	rb(s);
	write(1, "rr\n", 3);
}
