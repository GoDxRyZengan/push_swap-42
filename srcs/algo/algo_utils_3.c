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

void	new_algo_utils(t_stack *s)
{
	while (s->nb_a > 1)
	{
		s->m = 0;
		who_to_m_b(s);
		if (s->how == 'a')
			a_move(s);
		else if (s->how == 'c')
			c_move(s);
		else if (s->how == 'd')
			d_move(s);
		else
			b_move(s);
	}
}

void	new_algo_utils_2(t_stack *s)
{
	int	i;

	i = find_biggest_spe(s, 0);
	if (i > s->nb_b / 2)
	{
		while (i < s->nb_b)
		{
			rrb(s);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(s);
			i--;
		}
	}
}
