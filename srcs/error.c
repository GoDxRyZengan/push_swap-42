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

void	error_utils_2(t_stack *s)
{
	t_cmd	*tmp;
	t_cmd	*curr;

	curr = s->first_cmd;
	free(s->stack_a);
	free(s->stack_b);
	while (curr)
	{
		free(tmp->str);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(s);
}


void	error_utils(int i, t_stack *s)
{
	t_cmd	*tmp;
	t_cmd	*curr;

	if (i == 4)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s->stack_b);
		free(s);
		exit(1);
	}
	curr = s->first_cmd;
	if (i == 5)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s->stack_b);
		while (curr)
		{
			free(tmp->str);
			tmp = curr->next;
			free(curr);
			curr = tmp;
		}
		free(s);
		exit(1);
	}
	if (i == 6)
		error_utils_2(s);
}

void	error(int i, t_stack *s)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		free(s);
		exit(1);
	}
	if (i == 2)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s);
		exit(1);
	}
	if (i == 3)
	{
		write(2, "Error\n", 6);
		free(s->stack_a);
		free(s->stack_b);
		free(s);
		exit(1);
	}
	if (i == 4)
		error_utils(4, s);
	if (i == 5)
			error_utils(4, s);
}
