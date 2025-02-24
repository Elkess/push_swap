/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:27:52 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 20:12:17 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_new_node(int value, int index)
{
	t_stack	*newnode;

	newnode = ft_malloc(sizeof(t_stack));
	newnode->value = value;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
}

static t_stack	*append_node(t_stack *head, t_stack *newnode)
{
	t_stack	*tmp;

	tmp = head;
	if (!head)
		return (newnode);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
	return (head);
}

t_stack	*initiate_stack(t_stack *stack, int *arr, size_t len)
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
