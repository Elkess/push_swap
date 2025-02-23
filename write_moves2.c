/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:41:09 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 09:34:29 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rra(t_stack_node **a)
{
	rrotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rrotate_stack(b);
	write(1, "rrb\n", 4);
}
