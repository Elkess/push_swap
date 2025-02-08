/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 13:11:37 by melkess           #+#    #+#             */
/*   Updated: 2025-02-08 13:11:37 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(void)
{
	write(2, "Error\n", 6);
}
// void	fillStack(t_stack_node **stack)
// {
// 	size_t	i;
// 	t_stack_node *a;

// 	a = *stack;
// 	i = 0;
// 	while (a)
// 	{
// 		a->index = i;
// 		a->next = NULL;
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (checkargs(ac, ++av))
		return (handle_error(), 1);
	// fillStack(a_stack);
	return (0);
}