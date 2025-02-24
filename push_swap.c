/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:19 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 21:52:58 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max( t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack->next)
	{
		if (max->value < stack->next->value)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

static void	handle_error(void)
{
	write(2, "Error\n", 6);
	ft_exit(1);
}

static size_t	avlen(char	**av)
{
	size_t	i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

static int	*transform_to_numbers(char **av)
{
	size_t	i;
	size_t	len;
	int		*arr;

	len = avlen(av);
	arr = ft_malloc(len * sizeof(int));
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

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac == 1)
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	if ((ac == 2 && !av[1][0]))
		return (handle_error(), 1);
	av = checkargs(&ac, ++av);
	if (ac)
		return (handle_error(), 1);
	a_stack = initiate_stack(a_stack, transform_to_numbers(av), avlen(av));
	if (!is_it_sorted(a_stack))
	{
		if (avlen(av) == 2)
			sort_two(&a_stack);
		else if (avlen(av) == 3)
			sort_three(&a_stack);
		else
			sorting(&a_stack, &b_stack, transform_to_numbers(av), avlen(av));
	}
	ft_exit(0);
}
