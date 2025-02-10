/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:14:49 by melkess           #+#    #+#             */
/*   Updated: 2025/02/10 11:23:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	size_t				index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	// struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	// struct s_stack_node	*prev;
}						t_stack_node;

long			ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			**checkargs(int *ac, char **av);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
t_stack_node	*initiate_stack(t_stack_node *stack, int	*arr, int len);
int				is_it_sorted(t_stack_node *stack);
char			*sorting(t_stack_node *a, t_stack_node *b);

// Handle errors DONE

// Stack initiation DONE

//Nodes initiation DONE

//Stack utils

//Commands

//Algorithms

#endif