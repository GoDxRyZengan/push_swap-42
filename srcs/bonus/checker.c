/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:02:28 by hucoulon          #+#    #+#             */
/*   Updated: 2022/05/26 19:02:31 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_op(t_stack *s, char *str)
{
	printf("%s\n", str);
	if (ft_strcmp(str, "sa") == 1)
		bonus_sa(s);
	else if (ft_strcmp(str, "sb") == 1)
		bonus_sb(s);
	else if (ft_strcmp(str, "ss") == 1)
		bonus_ss(s);
	else if (ft_strcmp(str, "pa") == 1)
		bonus_pa(s);
	else if (ft_strcmp(str, "pb") == 1)
		bonus_pb(s);
	else if (ft_strcmp(str, "ra") == 1)
		bonus_ra(s);
	else if (ft_strcmp(str, "rb") == 1)
		bonus_rb(s);
	else if (ft_strcmp(str, "rr") == 1)
		bonus_rr(s);
	else if (ft_strcmp(str, "rra") == 1)
		bonus_rra(s);
	else if (ft_strcmp(str, "rrb") == 1)
		bonus_rrb(s);
	else if (ft_strcmp(str, "rrr") == 1)
		bonus_rrr(s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	launch_cmd(t_stack *s, char *str, char *buf)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\n' && str[i])
		{
			buf[j] = str[i];
			j++;
			i++;
		}
		buf[j] = '\0';
		do_op(s, buf);
		i++;
	}
}

void	checker(t_stack *s)
{
	char	*buf;
	char	*tmp;
	int		res;

	res = 2;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (res > 1)
	{
		res = read(0, buf, BUFFER_SIZE);
		buf[res] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	launch_cmd(s, tmp, buf);
}

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
	checker(&s);
	if (check_if_right(&s) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(s.stack_b);
	free(s.stack_a);
	return (0);
}
