/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:14:34 by codespace         #+#    #+#             */
/*   Updated: 2025/02/10 11:20:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_it_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}