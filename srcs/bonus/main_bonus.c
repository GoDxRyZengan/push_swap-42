#include "../../include/push_swap.h"

t_cmd	*new_link(char *str)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd*));
	if (!cmd)
		return (NULL);
	if (str == NULL)
		cmd->str = NULL;
	cmd->str = str;
	return (cmd);
}

void	add_link(t_stack *s, t_cmd *add_link)
{
	t_cmd	*tmp;
	if (s->first_cmd == NULL)
		s->first_cmd = add_link;
	else
	{
		tmp = s->first_cmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

t_stack	*init_stack(void)
{
	t_stack *s;

	s = malloc(sizeof(t_stack*));
	if (!s)
		return (NULL);
	s->first_cmd = NULL;
	return (s);
}

int		is_cmd(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0)
		return (0);
	if (ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "rr") == 0)
		return (0);
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		return (0);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0)
		return (0);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0)
		return (0);
	if (ft_strcmp(str, "rrr") == 0)
		return (0);
	return (-1);
}

void	do_op(t_stack *s, t_cmd *cmd)
{
	if (ft_strcmp(cmd->str, "sa") == 0)
		sa(s);
	if (ft_strcmp(cmd->str, "sb") == 0)
		sb(s);
	if (ft_strcmp(cmd->str, "ss") == 0)
		ss(s);
	if (ft_strcmp(cmd->str, "pa") == 0)
		pa(s);
	if (ft_strcmp(cmd->str, "pb") == 0)
		pb(s);
	if (ft_strcmp(cmd->str, "ra") == 0)
		ra(s);
	if (ft_strcmp(cmd->str, "rb") == 0)
		rb(s);
	if (ft_strcmp(cmd->str, "rr") == 0)
		rr(s);
	if (ft_strcmp(cmd->str, "rra") == 0)
		rra(s);
	if (ft_strcmp(cmd->str, "rrb") == 0)
		rrb(s);
	if (ft_strcmp(cmd->str, "rrr") == 0)
		rrr(s);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	t_cmd	*tmp;
	char	*buf;
	int		res;

	res = 0;
	s = init_stack();
	if (argc < 2)
		return (0);
	if ((check_arg(argv)) == 1)
		error(1, s);
	s->stack_a = (create_stack(argc));
	if (s->stack_a == NULL)
		error(1, s);
	s->stack_b = (create_stack(argc));
	if (s->stack_b == NULL)
		error(2, s);
	s->stack_a = (fill_stack(argv, s->stack_a));
	s->nb_a = argc - 1;
	s->nb_b = 0;
	if (check_duplicate_spe(s->stack_a, s->nb_a) == 1)
		error(3, s);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		error(4, s);
	while ((res = read(0, buf, BUFFER_SIZE)) > 0)
	{
		if (res < 0)
			break;
		buf[res] = '\0';
		if (is_cmd(buf) !=0)
			error(5, s);
		tmp = new_link(buf);
		add_link(s, tmp);
	}
	tmp = s->first_cmd;
	while (tmp)
	{
		do_op(s, tmp);
		tmp = tmp->next;
	}
	if (check_if_right(s) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	error(6, s);
	return (0);
}
