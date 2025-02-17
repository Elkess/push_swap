/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:55:13 by melkess           #+#    #+#             */
/*   Updated: 2025/02/17 20:02:11 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr, int flag)
{
	static void	*lst[INT_MAX];
	static int	i;
	int			j;
	if (flag)
	{
		j = 0;
		while (lst[j])
			free(lst[j++]);
	}
	else
		lst[i++] = ptr;
}

void	ft_exit(int status)
{
	ft_free(NULL, 1);
	if (status)
		perror("");
	exit(status);
}

void	*ft_malloc(size_t n)
{
	void	*ptr;

	ptr = malloc(n);
	if (!ptr)
		ft_exit(1);
	ft_free(ptr, 0);
	return (ptr);
}