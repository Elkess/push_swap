/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:27:52 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 08:52:43 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*create_new_node(int value, int index)
{
	t_stack_node	*newnode;

	newnode = ft_malloc(sizeof(t_stack_node));
	newnode->value = value;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
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

t_stack_node	*initiate_stack(t_stack_node *stack, int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		stack = append_node(stack, create_new_node(arr[i], i));
		i++;
	}
	return (stack);
}
