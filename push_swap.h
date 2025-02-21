/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:28 by melkess           #+#    #+#             */
/*   Updated: 2025/02/21 17:28:25 by melkess          ###   ########.fr       */
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

void			*ft_malloc(size_t n);
void			ft_exit(int n);
// void			free_stack(t_stack_node *stack);
// void			ft_free(char **str);

long			ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			**checkargs(int *ac, char **av);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
t_stack_node	*initiate_stack(t_stack_node *stack, int	*arr, size_t len);
int				is_it_sorted(t_stack_node *stack);

// moves
void			swap_stack(t_stack_node **stack);
void			rotate_stack(t_stack_node **stack);
void			push_from_s1_to_s2(t_stack_node **s1, t_stack_node **s2);
void			rrotate_stack(t_stack_node **stack);

// operations
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);

void			ra(t_stack_node **a);
void			rb(t_stack_node **b);

void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);

// Global moves
void			swap(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **a, t_stack_node **b);
void			rrotate(t_stack_node **a, t_stack_node **b);

// Sorting
void			sort_two(t_stack_node **stack);
void			sort_three(t_stack_node **stack);
void			sorting(t_stack_node **a, t_stack_node **b,
					int *arr, size_t len);

#endif
