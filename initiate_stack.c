/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:39:33 by codespace         #+#    #+#             */
/*   Updated: 2025/02/10 10:59:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*create_new_node(int value, int index)
{
	t_stack_node	*newnode;

	newnode = malloc(sizeof(t_stack_node));
	newnode->value = value;
	newnode->index = index;
	newnode->push_cost = 0;
	newnode->above_median = 0;
	newnode->cheapest = 0;
	// newnode->target_node = NULL;
	newnode->next = NULL;
	// newnode->prev = NULL;
}

static t_stack_node	*append_node(t_stack_node *head, t_stack_node *newnode)
{
	t_stack_node	*tmp;

	tmp = head;
	if (!head)
		return (newnode);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
	return (head);
}

t_stack_node	*initiate_stack(t_stack_node *stack, int	*arr, int len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		stack = append_node(stack , create_new_node(arr[i], i));
		i++;
	}
	return (stack);
}