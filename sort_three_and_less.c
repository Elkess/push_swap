/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_and_less.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:34 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 09:41:02 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **stack)
{
	t_stack_node	*node;

	node = *stack;
	if (find_max(node)->value == node->value)
		sa(stack);
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*node;
	int				max;

	node = *stack;
	max = find_max(node)->value;
	if (max == node->value)
		ra(stack);
	else if (max == node->next->value)
		rra(stack);
	node = *stack;
	if (node->value > node->next->value)
		sa(stack);
}
