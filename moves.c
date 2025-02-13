/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:04 by melkess           #+#    #+#             */
/*   Updated: 2025/02/13 09:07:56 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack_node **stack)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp1->next->next;
	tmp2->next = tmp1;
	*stack = tmp2;
}

void	rotate_stack(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	push_from_s1_to_s2(t_stack_node **s1, t_stack_node **s2)
{
	t_stack_node	*tmp;

	if (!(*s1))
		return ;
	tmp = *s2;
	(*s2) = *s1;
	*s1 = (*s1)->next;
	if (!(*s2))
		(*s2)->next = NULL;
	else
		(*s2)->next = tmp;
}

void	rrotate_stack(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*beforelast;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	beforelast = NULL;
	while (last->next)
	{
		beforelast = last;
		last = last->next;
	}
	*stack = last;
	beforelast->next = NULL;
	last->next = first;
}
