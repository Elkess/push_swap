#include <libc.h>
#include "push_swap.h"

//char	*push_swap(char	*s)
//{
//	int	*stacka;
//	int	*stackb;


//	return stacka;
//}
//void	haveTheyValidFormat(char **av)
//{
//	int	i;

//	i = 1;
//	while (av[i])
//	{
//		printf("%d\n", ft_atoi(av[i++]));
//	}
//}

void	handleError()
{
	write(2, "Error\n",6);
}
int	checkargs(int ac, char **av){
	int		notDigit;
	int		i = 0;
	int		j = 0;

	notDigit = 0;
	while(av[j])
	{
		i = 0;
		while(av[j][i])
		{
			if ( av[j][i] < '0' || av[j][i]> '9')
				notDigit = 1;
			i++;
		}
		j++;
	}

	if (notDigit)
		return (1);
	printf("%d", ft_atoi(*av));
	return (0);
}
int main(int ac, char **av)
{
	t_stack_node *astack;
	t_stack_node *bstack;

	astack = NULL;
	bstack = NULL;
	//printf("%d",checkargs(ac, ++av));
	if (
		//ac < 2 || av[1] == NULL ||
	 checkargs(ac, ++av))
		return (handleError(),0);
}