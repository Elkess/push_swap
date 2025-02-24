/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:28:28 by melkess           #+#    #+#             */
/*   Updated: 2025/02/24 21:09:06 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <libc.h>

typedef struct s_stack_node
{
	int					value;
	size_t				index;
	struct s_stack_node	*next;
}						t_stack;

void			*ft_malloc(size_t n);
void			ft_exit(int n);
t_stack			*find_max( t_stack *stack);
long			ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			**checkargs(int *ac, char **av);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
size_t			stack_len(t_stack *stack);
t_stack			*initiate_stack(t_stack *stack, int	*arr, size_t len);
int				is_it_sorted(t_stack *stack);
void			swap_stack(t_stack **stack);
void			rotate_stack(t_stack **stack);
void			push_from_s1_to_s2(t_stack **s1, t_stack **s2);
void			rrotate_stack(t_stack **stack);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			swap(t_stack **a, t_stack **b);
void			rotate(t_stack **a, t_stack **b);
void			rrotate(t_stack **a, t_stack **b);
void			sort_two(t_stack **stack);
void			sort_three(t_stack **stack);
void			sorting(t_stack **a, t_stack **b,
					int *arr, size_t len);
void			sortb(t_stack **a, t_stack **b );
void			rsortb(t_stack **a, t_stack **b );
int				ft_mini_sort(t_stack *list);

#endif
