/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:11:37 by melkess           #+#    #+#             */
/*   Updated: 2025/02/09 05:51:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(void)
{
	write(2, "Error\n", 6);
}

size_t	avlen(char	**av)
{
	size_t	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int *transform_to_numbers(char **av)
{
	size_t	i;
	size_t	len;
	int		*arr;

	len = avlen(av);
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
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
	int				*arr;

	if (ac <= 1)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	av = checkargs(&ac, ++av);
	if (ac)
		return (handle_error(), 1);
	arr = transform_to_numbers(av);
	for (size_t i = 0; i < avlen(av); i++)
	{
		printf("{%d}", arr[i]);
	}
	
	// fillStack(a_stack);
	return (0);
}