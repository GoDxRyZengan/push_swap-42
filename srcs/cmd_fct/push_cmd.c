/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:36:40 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 18:37:14 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	ft_swap_a(t_stack *s, int *swap_a)
{
	int	i;

	i = 0;
	swap_a[0] = s->stack_b[0];
	while (i < s->nb_a)
	{
		swap_a[i + 1] = s->stack_a[i];
		i++;
	}
	return (i);
}

int	ft_swap_b(t_stack *s, int *swap_b)
{
	int	i;

	i = 0;
	swap_b[0] = s->stack_a[0];
	while (i < s->nb_b)
	{
		swap_b[i + 1] = s->stack_b[i];
		i++;
	}
	return (i);
}

void	pa(t_stack *s)
{
	int	*swap_a;
	int	*swap_b;
	int	i;

	i = 0;
	if (s->nb_b != 0)
	{
		swap_a = create_stack(s->nb_a + 1);
		swap_b = create_stack(s->nb_b - 1);
		s->nb_a = ft_swap_a(s, swap_a) + 1;
		i = 0;
		while (i < s->nb_b - 1)
		{
			swap_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->nb_b = i;
		free(s->stack_a);
		free(s->stack_b);
		s->stack_a = swap_a;
		s->stack_b = swap_b;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *s)
{
	int	*swap_a;
	int	*swap_b;
	int	i;

	i = 0;
	if (s->nb_a != 0)
	{
		swap_a = create_stack(s->nb_a - 1);
		swap_b = create_stack(s->nb_b + 1);
		s->nb_b = (ft_swap_b(s, swap_b)) + 1;
		i = 0;
		while (i < s->nb_a - 1)
		{
			swap_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->nb_a = i;
		free(s->stack_a);
		free(s->stack_b);
		s->stack_a = swap_a;
		s->stack_b = swap_b;
	}
	write(1, "pb\n", 3);
}
