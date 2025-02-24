/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:40 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 20:27:12 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_arr(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < len)
	{
		j = i +1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static void	index_stack(t_stack **a, int *arr, size_t len)
{
	size_t			i;
	t_stack			*tmp ;

	arr = sort_arr(arr, len);
	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static int	is_reversed(t_stack *a)
{
	size_t	len;

	len = stack_len(a);
	while (a->next)
	{
		if (a->value > a->next->value)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

static void	empty_astack(t_stack **a, t_stack **b, int mid)
{
	size_t	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index < i + mid)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (ft_mini_sort(*a) == 1)
			rra(a);
		else
			ra(a);
	}
}

void	sorting(t_stack **a, t_stack **b, int *arr, size_t len)
{
	int	mid;

	if (len <= 100)
		mid = 11;
	else
		mid = 37;
	index_stack(a, arr, len);
	if (!is_reversed(*a))
	{
		empty_astack(a, b, mid);
		sortb(a, b);
	}
	else
		rsortb(a, b);
}
