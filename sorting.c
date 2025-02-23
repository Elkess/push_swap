/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:40 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 09:26:01 by melkess          ###   ########.fr       */
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

void	index_stack(t_stack_node **a, int *arr, size_t len)
{
	size_t			i;
	t_stack_node	*tmp ;

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

int	is_reversed(t_stack_node *a)
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

void	empty_astack(t_stack_node **a, t_stack_node **b, size_t len, int mid)
{
	size_t			i;

	i = 0;
	len = stack_len(*a);
	while (len)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
			len--;
		}
		else if ((*a)->index < i + mid)
		{
			pb(a, b);
			rb(b);
			i++;
			len--;
		}
		else if (ft_mini_sort(*a) == 1)
			rra(a);
		else
			ra(a);
	}
}

void	sorting(t_stack_node **a, t_stack_node **b, int *arr, size_t len)
{
	int	mid;

	if (len <= 100)
		mid = 11;
	else
		mid = 38;
	index_stack(a, arr, len);
	if (!is_reversed(*a))
	{
		empty_astack(a, b, len, mid);
		sortb(a, b);
	}
	else
		rsortb(a, b);
}
