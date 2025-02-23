/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:41:09 by melkess           #+#    #+#             */
/*   Updated: 2025/02/23 09:34:19 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_from_s1_to_s2(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_from_s1_to_s2(a, b);
	write(1, "pb\n", 3);
}

void	sa(t_stack_node **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}
