/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:04:45 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 09:21:28 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sortbh(size_t counter, size_t len, t_stack_node **b, t_stack_node *max)
{
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
}

void	sortb(t_stack_node **a, t_stack_node **b )
{
	t_stack_node	*tmp;
	t_stack_node	*max;
	size_t			len;
	size_t			counter;

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
		sortbh(counter, len, b, max);
		pa(a, b);
		counter = 0;
		len--;
	}
}

void	rsortb(t_stack_node **a, t_stack_node **b )
{
	while (*a)
	{
		rra(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}

int	ft_mini_sort(t_stack_node *list)
{
	int	count;
	int	espace;

	count = 0;
	espace = 0;
	while (list && list->next)
	{
		espace = list->value - list->next->value;
		if (espace == 2 || espace == 3)
			count++;
		list = list->next;
	}
	if (count >= 15 && count <= 498)
		return (1);
	return (0);
}
