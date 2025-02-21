/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:40 by melkess           #+#    #+#             */
/*   Updated: 2025/02/21 17:32:09 by melkess          ###   ########.fr       */
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

t_stack_node	*find_max( t_stack_node *stack)
{
	t_stack_node	*max;

	max = stack;
	while (stack->next)
	{
		if (max->value < stack->next->value)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

size_t	stack_len(t_stack_node *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sortb(t_stack_node **a, t_stack_node **b )
{
	t_stack_node	*tmp;
	t_stack_node	*max;
	size_t			i;
	size_t			len;
	size_t			counter;

	i = 0;
	counter = 0;
	len = stack_len(*b);
	while (len)
	{
		tmp = *b;
		max = find_max(*b);
		while (tmp != max)
		{
			counter++;
			tmp = tmp->next;
		}
		if (counter <= len / 2)
		{
			while (*b != max)
				rb(b);
		}
		if (counter > len / 2)
		{
			while (*b != max)
				rrb(b);
		}
		pa(a, b);
		counter = 0;
		len--;
	}
}

void	empty_astack(t_stack_node **a, t_stack_node **b, size_t len, int mid)
{
	size_t			i;

	i = 0;
	(void)len;
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
		else
			ra(a);
	}
}

void	wich_is_above_median(t_stack_node *b)
{
	t_stack_node	*head;
	size_t			len;
	size_t			i;

	i = 0;
	len = stack_len(b);
	head = b;
	while (len--)
	{
		head->index = i++;
		head = head->next;
	}
	len = stack_len(b) / 2;
	while (len--)
	{
		b->above_median = 1;
		b = b->next;
	}
}

void	sorting(t_stack_node **a, t_stack_node **b, int *arr, size_t len)
{
	int	mid;

	mid = len / 2;
	arr = sort_arr(arr, len);
	index_stack(a, arr, len);
	empty_astack(a, b, len, mid);
	wich_is_above_median(*b);
	sortb(a, b);
}
