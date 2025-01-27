/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:35:08 by melkess           #+#    #+#             */
/*   Updated: 2025/01/18 19:43:05 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		result;
	long long		temp;

	sign = 1;
	i = 0;
	result = 0;
	ft_skip(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = result;
		result = result * 10 + str[i] - 48;
		if (result / 10 != temp)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (result * sign);
}
