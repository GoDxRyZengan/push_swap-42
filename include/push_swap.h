/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:38:44 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/21 00:38:47 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		nb_a;
	int		nb_b;
	int		to_m;
	char	tmp;
	char	how;
	int		m;
}				t_stack;

int			check_arg(char **argv);
int			*create_stack(int argc);
int			*fill_stack(char **argv, int *stack);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_duplicate(char **argv, char *str, int i);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen(char const *str);
void		error(int i);
void		push_swap(t_stack *s);
int			check_if_right(t_stack *s);
void		sa(t_stack *s);
void		sb(t_stack *s);
void		ss(t_stack *s);
void		ra(t_stack *s);
void		rb(t_stack *s);
void		rr(t_stack *s);
void		rra(t_stack *s);
void		rrb(t_stack *s);
void		rrr(t_stack *s);
void		pa(t_stack *s);
void		pb(t_stack *s);
void		three_algo(t_stack *s);
void		five_algo(t_stack *s);
void		new_algo(t_stack *s);
void		new_algo_utils(t_stack *s);
void		new_algo_utils_2(t_stack *s);
int			find_smallest_a(t_stack *s);
int			find_smallest(t_stack *s);
int			find_biggest(t_stack *s, int index, int k);
int			find_big(t_stack *s, int index);
int			find_biggest_spe(t_stack *s, int index);
int			find_biggest_spe_utils(t_stack *s, int index, int tmp, int res);
void		who_to_m_b(t_stack *s);
void		who_to_m_b_utils(t_stack *s, int i);
int			m_to_r_b(t_stack *s, int index);
void		a_move(t_stack *s);
void		b_move(t_stack *s);
void		c_move(t_stack *s);
void		d_move(t_stack *s);
#endif 
