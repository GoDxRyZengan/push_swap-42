/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:27:48 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 18:27:59 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	error(int i, t_stack *s)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (i == 2)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		exit(1);
	}
	if (i == 3)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s->stack_b);
		exit(1);
	}
}
