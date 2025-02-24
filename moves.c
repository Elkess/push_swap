/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:04 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 20:12:17 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp1->next->next;
	tmp2->next = tmp1;
	*stack = tmp2;
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

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

void	push_from_s1_to_s2(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!s1 || !*s1)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
}

void	rrotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*beforelast;

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
