/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:54:24 by melkess           #+#    #+#             */
/*   Updated: 2025/02/11 08:40:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_there_duplicates(char **av)
{
	int	i;
	int	j;
	int	boolean;

	i = 0;
	j = 0;
	boolean = 0;
	while (av[i])
	{
		j = i +1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]) || (ft_atoi(av[i]) == ft_atoi(av[j])))
				boolean = 1;
			j++;
		}
		i++;
	}
	return (boolean);
}

static int	is_not_digit(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (1);
	if ((s[i] == '-' || s[i] == '+') && s[i +1])
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	is_int(char *s)
{
	if (ft_atoi(s) > INT_MAX || ft_atoi(s) < INT_MIN)
		return (1);
	return (0);
}
void ft_free(char **str)
{
	int i = 0;
	if (!str)
		return ;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**prepare_av(char	**av)
{
	char	**newav;
	char	*s;
	char	*tmp;
	int		i;
	int		j;

	newav = NULL;
	s = NULL;
	i = 0;
	while (av[i])
	{
		ft_free(newav);
		newav = ft_split(av[i++], ' ');
		j = 0;
		while (newav[j])
		{
			tmp = s;
			s = ft_strjoin(s, newav[j++]);
			free(tmp);
			tmp = s;
			s = ft_strjoin(s, " ");
			free(tmp);
		}
	}
	return (ft_free(newav), av = ft_split(s, ' '), free(s), av);
}

int	is_av_full_of_spaces(char **s)
{
	int	i;
	int	j;
	int	n;
	int	count;

	i = 0;
	n = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		count = 0;
		while (s[i][j])
		{
			if (s[i][j] == ' ')
				count++;
			j++;
		}
		if (count == j)
			n = 1;
		i++;
	}
	return (n);
}

char	**checkargs(int *ac, char **av)
{
	int	i;
	int	n;

	*ac = 0;
	n = is_av_full_of_spaces(av);
	av = prepare_av(av);
	if (!av)
		return (*ac = 1, NULL);
	i = 0;
	while (av[i])
	{
		if (is_there_duplicates(av)
			|| is_not_digit(av[i]) || is_int(av[i]) || n)
			*ac = 1;
		i++;
	}
	return (av);
}
