/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:18:21 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 18:18:43 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	*create_stack(int size)
{
	int	*stack;

	stack = malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	return (stack);
}

int	*fill_stack(char **argv, int *stack)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		stack[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (stack);
}
