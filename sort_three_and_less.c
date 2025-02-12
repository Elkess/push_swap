/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_and_less.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:31:35 by codespace         #+#    #+#             */
/*   Updated: 2025/02/12 14:31:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

static int	max_node(t_stack_node *node)
{
	int	max;

	max = node->value;
	while (node->next)
	{
		if (max < node->next->value)
			max = node->next->value;
		node = node->next;
	}
	return (max);
}

void	sort_two(t_stack_node **stack)
{
	t_stack_node	*node;

	node = *stack;
	if (max_node(node) == node->value)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
	}
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*node;
	int				max;

	node = *stack;
	max = max_node(node);
	if (max == node->value)
	{
		rotate_stack(stack);
		write(1, "ra\n", 3);
	}
	else if (max == node->next->value)
	{
		rrotate_stack(stack);
		write(1, "rra\n", 4);

	}
	node = *stack;
	if (node->value > node->next->value)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
	}

}
