/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:11:37 by melkess           #+#    #+#             */
/*   Updated: 2025/02/12 12:05:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(void)
{
	write(2, "Error\n", 6);
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

int	main(int ac, char **av)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;
	int				*arr;

	if (ac == 1)
		return (1);
	a_stack = NULL;
	b_stack = NULL;
	if ((ac == 2 && !av[1][0]))
		return (handle_error(), 1);
	
	av = checkargs(&ac, ++av);
	if (ac)
		return (handle_error(), 1);
	arr = transform_to_numbers(av);
	a_stack = initiate_stack(a_stack, arr, avlen(av));
	if (!is_it_sorted(a_stack))
	{
		printf("%s\n", sorting(a_stack, b_stack));
		if (avlen(av) == 2)
			puts("sort 2");
		else if (avlen(av) == 3)
			puts("sort 3");
		else
			puts("sorting more");
	}
	else
		puts("sorted");
	t_stack_node	*stack1 = a_stack;
	t_stack_node	*stack2 = b_stack;
	
	// while (stack1)
	// {
	// 	printf("%d\n", stack1->value);
	// 	stack1 = stack1->next;
	// }
	// rrotate_stack(&a_stack);
	// rrotate_stack(&a_stack);
	// swap_stack(&b_stack);
	// rotate_stack(&b_stack);
	// push_from_stack1_to_stack2(&a_stack, &b_stack);
	push_from_stack1_to_stack2(&a_stack, &b_stack);
	push_from_stack1_to_stack2(&a_stack, &b_stack);
	push_from_stack1_to_stack2(&a_stack, &b_stack);
stack1 = a_stack;
stack2 = b_stack;
	puts("----A STACK ----");
	while (stack1)
	{
		printf("%d\n", stack1->value);
		stack1 = stack1->next;
	}
	puts("----B STACK ----");

	while (stack2)
	{
		printf("%d\n", stack2->value);
		stack2 = stack2->next;
	}
	// free_stack(&a_stack);

	// swap(&a_stack, &b_stack);
	rrotate(&a_stack, &b_stack);
	puts("----A STACK ----");
	while (a_stack)
	{
		printf("%d\n", a_stack->value);
		a_stack = a_stack->next;
	}
	puts("----B STACK ----");

	while (b_stack)
	{
		printf("%d\n", b_stack->value);
		b_stack = b_stack->next;
	}
	return (0);
}
