#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	nb_a;
	int	nb_b;
}				t_stack;

int     check_arg(char** argv);
int     *create_stack(int argc);
int     *fill_stack(char **argv, int *stack);
long int     ft_atoi(const char *str);
int     ft_isdigit(int c);
int check_duplicate(char **argv, char *str, int i);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strlen(char const *str);
void	error(int i);
void	push_swap(t_stack *s);
int	check_if_right(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	three_algo(t_stack *s);
void	five_algo(t_stack *s);

// a enlever
void	print_stack(t_stack *s);
#endif 