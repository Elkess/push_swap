/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:14:49 by melkess           #+#    #+#             */
/*   Updated: 2025/02/09 05:53:16 by codespace        ###   ########.fr       */
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
	int					n;
	size_t				index;
	int					push_cost;
	char				above_median;
	char				cheapest;
	// struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	// struct s_stack_node	*prev;
}						t_stack_node;

long	ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	**checkargs(int *ac, char **av);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// Handle errors DONE

// Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif