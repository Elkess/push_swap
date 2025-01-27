/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:04:21 by melkess           #+#    #+#             */
/*   Updated: 2025/01/18 18:19:07 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

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
} t_stack_node;


int	ft_atoi(const char *str);


// Handle errors

// Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif