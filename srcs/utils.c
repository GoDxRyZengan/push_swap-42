/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:14:03 by hucoulon          #+#    #+#             */
/*   Updated: 2022/03/20 18:14:31 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

long int	ft_atoi(const char *str)
{
	long int	a;
	long int	res;
	long int	neg;

	neg = 1;
	res = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] > 6 && str[a] < 14))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			neg = -1;
		a++;
	}
	while (str[a] > 47 && str[a] < 58)
	{
		res = res * 10 + (str[a] - 48);
		a++;
	}
	return (res * neg);
}

int	ft_isdigit(int c)
{
	unsigned char	a;

	a = c;
	if (a > 47 && a < 58)
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while ((s1[a]) || (s2[a]))
	{
		if (s1[a] == s2[a])
			a++;
		else
			return (0);
	}
	return (1);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
