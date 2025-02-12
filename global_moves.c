/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:13:38 by melkess           #+#    #+#             */
/*   Updated: 2025/02/12 12:05:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **a, t_stack_node **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	rotate(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	rrotate(t_stack_node **a, t_stack_node **b)
{
	rrotate_stack(a);
	rrotate_stack(b);
}
