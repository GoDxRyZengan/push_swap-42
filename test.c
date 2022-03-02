#include <stdio.h>

long int	ft_atoi(const char *str)
{
	long int a;
	long int res;
	long int neg;

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

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;
	size_t	res;

	res = 0;
	a = 0;
	while ((s1[a] != '\0') || (s2[a] != '\0'))
	{
		printf("%c == %c\n", s1[a], s2[a]);
		if (s1[a] == s2[a])
			a++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 2)
	{
		printf("Pas assez d'arg :%d\n", argc);
		return (0);
	}
	printf("resultat :%ld\n", ft_atoi(argv[1]));
	return (0);
}