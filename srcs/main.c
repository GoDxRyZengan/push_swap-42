/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:02:13 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 18:09:51 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s;

	if (argc < 2)
		return (0);
	if ((check_arg(argv)) == 1)
		error(1, &s);
	s.stack_a = (create_stack(argc));
	if (s.stack_a == NULL)
		error(1, &s);
	s.stack_b = (create_stack(argc));
	if (s.stack_b == NULL)
		error(2, &s);
	s.stack_a = (fill_stack(argv, s.stack_a));
	s.nb_a = argc - 1;
	s.nb_b = 0;
	if (check_duplicate_spe(s.stack_a, s.nb_a) == 1)
		error(3, &s);
	push_swap(&s);
	free(s.stack_b);
	free(s.stack_a);
	return (0);
}
