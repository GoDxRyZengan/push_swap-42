/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:35:09 by hucoulon          #+#    #+#             */
/*   Updated: 2022/02/25 14:35:14 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int check_duplicate(char **argv, char *str, int i)
{
    int j;

    j = 1;
    while (argv[j])
    {
        if (i == j)
            j++;
        else if ((argv[j][0] == '-' && argv[j][0] == '0' && str[0] == '0')
            || (str[0] == '-' && str[1] == '0' && argv[j][0] == '0'))
            return (1);
        else if (ft_strcmp(argv[j], str) == 1)
            return (1);
        else
            j++;
    }
    return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
    if (ft_strlen(str) > 11)
        return (1);
    if (ft_strlen(str) > 1)
    {
        if ((str[i] == '-') || (str[i] == '+'))
            i++;
    }
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	i = 0;
	if ((ft_atoi(str) > 2147483647) || (ft_atoi(str) < -2147483648))
		return (1);
	return (0);
}

int     check_arg(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        if (is_int(argv[i]) == 1)
            return (1);
        i++;
    }
    i = 1;
    while (argv[i])
    {
        if (check_duplicate(argv, argv[i], i) == 1)
            return (1);
        i++;
    }
    return (0);
}