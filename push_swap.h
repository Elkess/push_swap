/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 13:14:49 by melkess           #+#    #+#             */
/*   Updated: 2025-02-08 13:14:49 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					n;
	size_t				index;
	int					push_cost;
	char				above_median;
	char				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

long	ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		checkargs(int ac, char **av);

// Handle errors DONE

// Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif