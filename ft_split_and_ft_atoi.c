/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_ft_atoi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:26:51 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 19:50:07 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_skip(const char *str, int *i, int *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			result;

	sign = 1;
	i = 0;
	result = 0;
	ft_skip(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (((i > 9 && sign == 1) || (i > 10 && sign == -1))
			&& result > INT_MAX)
			return (2147483648);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

static int	ft_nbr_words(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s[0] != c && s[0] != '\0')
		n++;
	while (s[i])
	{
		if ((s[i] == c && s[i +1] != c && s[i +1] != '\0'))
			n++;
		i++;
	}
	return (n);
}

static char	*ft_one_word(const char *s, char c, int *i)
{
	int	start;
	int	end;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	end = *i;
	return (ft_substr(s, start, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**splitedstr;
	int		nbrwords;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nbrwords = ft_nbr_words(s, c);
	splitedstr = (char **) ft_malloc((nbrwords +1) * sizeof(char *));
	if (!splitedstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < nbrwords)
	{
		splitedstr[j] = ft_one_word(s, c, &i);
		j++;
	}
	splitedstr[j] = NULL;
	return (splitedstr);
}
