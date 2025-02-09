/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:11:37 by melkess           #+#    #+#             */
/*   Updated: 2025/02/09 14:31:30 by codespace        ###   ########.fr       */
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

// t_stack_node	*fillStack(t_stack_node *stack, int	*arr, int len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		stack = ft_append_node(stack , ft_create_new_node(arr[i]));
// 		i++;
// 	}
// 	return (stack);
// }
void ff()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	// atexit(ff);
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;
	int				*arr;

	if (ac <= 1)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	av = checkargs(&ac, ++av);
	arr = transform_to_numbers(av);
	if (ac)
		return (handle_error(), 1);
	for (size_t i = 0; i < avlen(av); i++)
	{
		printf("{%d}", arr[i]);
	}
	// a_stack = fillStack(a_stack, arr, avlen(av));
	return (0);
}