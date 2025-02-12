/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:54:05 by melkess           #+#    #+#             */
/*   Updated: 2025/02/12 21:29:46 by melkess          ###   ########.fr       */
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
