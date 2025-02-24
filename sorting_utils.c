/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:04:45 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 21:52:28 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sortbh(size_t counter, size_t len, t_stack **b, t_stack *max)
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

void	sortb(t_stack **a, t_stack **b )
{
	t_stack			*tmp;
	t_stack			*max;
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

void	rsortb(t_stack **a, t_stack **b )
{
	while (*a)
	{
		rra(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}

static int	ft_patern_checker(t_stack *stack, int dir, int peak, size_t up)
{
	t_stack	*head;

	head = stack;
	while (stack->next)
	{
		if (stack->index < stack->next->index)
		{
			if (dir == -1)
				return (0);
			dir = 1;
			up++;
		}
		else
		{
			if (dir == 1)
				peak = 1;
			dir = -1;
		}
		stack = stack->next;
	}
	if (peak && up > stack_len(head) / 4)
		return (1);
	return (0);
}

int	ft_mini_sort(t_stack *stack)
{
	size_t			down;
	t_stack			*list;
	int				direction;
	size_t			up;
	int				peak;

	peak = 0;
	up = 0;
	direction = 0;
	down = 0;
	list = stack;
	while (list->next)
	{
		if (list->index > list->next->index)
			down++;
		list = list->next;
	}
	if (down > (stack_len(stack) - 1) * 0.7)
		return (1);
	return (ft_patern_checker(stack, direction, peak, up));
}
