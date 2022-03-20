/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:03:11 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 23:03:13 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../../include/push_swap.h"

int	find_biggest_spe_utils(t_stack *s, int index, int tmp, int res)
{
	int	i;

	i = 0;
	while (i < s->nb_b)
	{
		if ((s->stack_a[index] > s->stack_b[i]) && (tmp < s->stack_b[i]))
		{
			tmp = s->stack_b[i];
			res = i;
			i = 0;
		}
		i++;
	}
	return (res);
}

void	who_to_m_b_utils(t_stack *s, int i)
{
	s->m = i + m_to_r_b(s, i);
	s->to_m = i;
	s->how = s->tmp;
}

int	find_big(t_stack *s, int index)
{
	int	i;

	i = 0;
	while (i < s->nb_b)
	{
		if (s->stack_a[index] > s->stack_b[i])
		{
			i = find_biggest(s, index, i);
			break ;
		}
		i++;
	}
	return (i);
}

int	find_biggest(t_stack *s, int index, int k)
{
	int	i;
	int	tmp;
	int	res;

	tmp = s->stack_b[k];
	res = k;
	i = 0;
	while (i < s->nb_b)
	{
		if ((s->stack_a[index] > s->stack_b[i]) && (tmp < s->stack_b[i]))
		{
			tmp = s->stack_b[i];
			res = i;
		}
		i++;
	}
	return (res);
}

int	find_smallest(t_stack *s)
{
	int	i;
	int	res;
	int	tmp;

	tmp = s->stack_b[0];
	res = 0;
	i = 0;
	while (i < s->nb_b)
	{
		if (s->stack_b[i] < tmp)
		{
			tmp = s->stack_b[i];
			res = i;
			i = 0;
		}
		else
			i++;
	}
	return (res);
}
